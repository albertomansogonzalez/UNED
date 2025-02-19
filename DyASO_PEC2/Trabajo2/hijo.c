//este archivo es el fichero fuente que al compilarse produce el ejecutable HIJO

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int wait_sem (int semid){
    struct sembuf op[1];
    op[0].sem_num = 0;
    op[0].sem_op = -1;
    op[0].sem_flg = 0;
    if (semop(semid, op, 1) == -1){
        perror ("Error semop");
        return -1;
    }
    return 0;

}


int signal_sem (int semid){
    struct sembuf op[1];
    op[0].sem_num = 0;
    op[0].sem_op = 1;
    op[0].sem_flg = 0;
    if (semop(semid, op, 1) == -1){
        perror ("Error semop");
        return -1;
    }
    return 0;
}




char estado [3];

void defensa(int sig){ //el proceso ha recibido un ataque pero lo ha repelido
    printf("El hijo %d ha repelido un ataque\n", getpid()); fflush(stdout);
    strcpy(estado, "OK");
}

void indefenso(int sig){ //el proceso ha recibido un ataque y no lo ha repelido
    printf("El hijo %d ha sido emboscado mientras realizaba un ataque\n", getpid()); fflush(stdout);
    strcpy(estado, "KO");
}

int main(int argc, char* argv[]){

    key_t clave = atoi(argv[1]);

    int pipefd[2];
    pipefd[0] = atoi(argv[2]); //descriptor de archivo de lectura de la tuberia sin nombre
    pipefd[1] = atoi(argv[3]); //descriptor de archivo de escritura de la tuberia sin nombre
    int N = atoi(argv[4]);  //nº de procesos hijos

    //Cierra el descriptor de fichero de escritura, ya que los hijos solo leen la barrera
    close(pipefd[1]);

    //Re-establecer los mecanismos IPC del padre

    //cola mensajes
    int msqid = msgget(clave, 0666);
    if (msqid == -1){
        perror("Error en msgget() en hijo");
    }

    //memoria compartida
    int shmid = shmget(clave, N * sizeof(pid_t), 0666);
    if (shmid == -1){
        perror("Error en shmget() en hijo");
    }
    pid_t* lista = shmat(shmid, NULL, 0);    //array con capacidad para N PIDs
    if (lista == (void *) -1){
        perror("Error en shmat() en hijo");
    }

    //semaforo
    int semid = semget(clave, 1, 0666);
    if (semid == -1){
        perror("Error en semget() en hijo");
    }

    pid_t mi_pid = getpid();

    //inicializamos aleatorio para uso "rand()"
    srand(mi_pid);    //utilizamos el PID para generar numero aleatorio

    //Esperar a la barrera leyendo tubería "barrera"
    while(1){

        char leido;
        if (read(pipefd[0], &leido, 1) < 1){ //esperar a barrera
            perror("Error en read()");
            exit(1);
        }
        //Fase Preparacion
        strcpy(estado, "OK");

        //Elegir ataca/defiende
        if (rand() % 2){ //El proceso hijo "ataca"
            printf("El %d ataca\n", mi_pid); fflush(stdout);

            if (signal(SIGUSR1, indefenso) == SIG_ERR){
                printf("error signal()"); fflush(stdout);
            }

            usleep(100000);

            //elegir PID random de la lista, (!= al propio)
            //recorrer la lista para contar los procesos vivos
            int K = 0; //K cuenta en nº de procesos vivos
            wait_sem(semid);
            for (int i = 0; i < N; i++){
                if (lista[i] != 0) K++;
            }
            signal_sem(semid);

            //printf("nº vivos = %d\n", K);

            int num = rand() % (K-1);   //se elige un nº aleatorio para elegir entre los vivos (menos el propio proceso)

            //recorrer la lista para encontrar el elegido
            wait_sem(semid);
            int i = -1;
            do{
                i++;
                //printf("  i: %d   num= %d\n", i, num);
                if ((lista[i] != 0) && (lista[i] != mi_pid)) num--;
            }while(num != -1);

            printf(" El %d ataca al %d\n", mi_pid, lista[i]); fflush(stdout);
            pid_t atacado = lista[i];

            if (atacado == 0 || atacado == mi_pid){
                printf("Error al elegir el atacado\n"); fflush(stdout);
            }
            signal_sem(semid);

            printf("Atacando al proceso %d\n", atacado); fflush(stdout);

            kill(atacado, SIGUSR1);

            usleep(100000);



        }else{
            //El hijo "defiende"

            printf("El %d defiende\n", mi_pid); fflush(stdout);

            if (signal(SIGUSR1, defensa) == SIG_ERR){
                printf("error signal()"); fflush(stdout);
            }

            usleep(200000);

        }

        //Enviar cola de mensaje al padre: PID propio y su estado
        struct {
            long msg_type; //tipo del mensaje
            pid_t pid;  //pid del proceso hijo que envia el mensaje
            char estado [3];
        }mensaje;

        int msgsz = sizeof(mensaje) - sizeof(long);
        mensaje.msg_type = 1;
        mensaje.pid = mi_pid;
        memcpy(mensaje.estado, estado, sizeof(estado));
        //printf("HIJO: pid:%d, estado = %s\n", mensaje.pid, mensaje.estado); fflush(stdout);
        if (msgsnd(msqid, &mensaje, msgsz, 0) == -1){
            perror("Error en msgsnd()");
        }


    }



    return 0;
}

