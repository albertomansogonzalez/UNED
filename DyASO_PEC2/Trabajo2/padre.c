//este archivo es el fichero fuente que al compilarse produce el ejecutable PADRE

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define FIFO_PATH "resultado"

int init_sem(int semid, ushort valor){
    ushort sem_array[1];
    sem_array[0] = valor;
    if (semctl(semid, 0, SETALL, sem_array) == -1){
        perror("Error semctl");
        return -1;
    }
    return 0;
}

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

int main(int argc, char* argv[]){

    if (argc != 3){
        printf("Error nº argumentos");
        return -1;
    }

    const char* ejecutable = argv[0];   //nombre del fichero ejecutable
    const char letra = argv[1][0];  //letra usada para ftok
    int N = atoi(argv[2]);  //nº de procesos hijos

    int K = N; //K es el nº de procesos vivos, inicialmente todos.

    //creamos clave asociada para generar todos los mecanismos IPC
    //primer argumento nombre del propio fichero ejecutable, segundo argumento una letra como 'X'
    key_t clave = ftok(ejecutable, letra);

    if (clave == -1){
        perror("Error en ftok()");
    }
    //tambien creamos la clave en formato string
    char clave_string[11];
    sprintf(clave_string, "%d", clave); //Convertir la clave a string

    //Crear cola de mensajes
    int msqid = msgget(clave, 0666 | IPC_CREAT);
    if (msqid == -1){
        perror("Error en msgget() en el padre");
        exit(1);
    }

    //Crear region de memoria compartida "lista"
    int shmid = shmget(clave, N * sizeof(pid_t), 0666 | IPC_CREAT);
    if (shmid == -1){
        perror("Error en shmeg() en padre");
    }
    pid_t* lista = (pid_t*)shmat(shmid, NULL, 0);    //array con capacidad para N PIDs
    if (lista == (void *) -1){
        perror("Error en shmat() en padre");
    }

    //Crear semaforo "sem"
    int semid = semget(clave, 1, 0666 | IPC_CREAT);
    if (semid == -1){
        perror("semget");
    }
   init_sem(semid, 1);


    //Crear tuberia sin nombre "barrera"
    int pipefd[2];  //pipefd[0]: lectura, pipefd[1]: escritura
    int res = pipe(pipefd);
    if (res == -1){
        perror("Error en pipe()");
    }
    char pipefd0_str [10];
    char pipefd1_str [10];
    sprintf(pipefd0_str, "%d", pipefd[0]); //Convertir el descriptor de archivo a string
    sprintf(pipefd1_str, "%d", pipefd[1]); //Convertir el descriptor de archivo a string


    //invocar N procesos hijos
    for (int i = 0; i < N; i++){
        pid_t pid = fork();

        if (pid < 0){
            perror("Error en fork()");
        }else if (pid == 0){
            //soy proceso hijo
            if (execl("./HIJO","HIJO", clave_string, pipefd0_str, pipefd1_str, argv[2] /*nº procesos hijos*/, NULL) == -1){
                perror("execl() ha fallado");
            }
        }else{ //codigo ejecutado por el padre
            //Inicializamos la lista
            wait_sem(semid);
            lista[i] = pid;
            signal_sem(semid);

        }
    }


    //Codigo del proceso Padre

    close(pipefd[0]);   //el padre cierra el extremo de lectura (el padre solo escribe en la tuberia)

    do{
        //inicio de ronda
        printf("\n\n ----- Iniciando ronda de ataques ----------------\n"); fflush(stdout);
        printf("Hijos vivos: %d\n", K); fflush(stdout);

        wait_sem(semid);
        printf("Imprimiendo lista:\n"); fflush(stdout);
        for (int i = 0; i < N; i++){
            printf(" %d: %d\n",i,lista[i]); fflush(stdout);
        }
        signal_sem(semid);
        printf("\n"); fflush(stdout);

        //enviar K bytes a la tubería "barrera" por cada hijo que quede vivo
        char byte = 'A';
        for (int i = 0; i < K; i++){
            write(pipefd[1], &byte , 1); //envia 1 byte
        }

        //Leer los K mensajes recibidos y comprobar estado contienda
        struct {
            long msg_type; //tipo del mensaje
            pid_t pid;  //pid del proceso hijo que envia el mensaje
            char estado [3];
        }mensaje;
        int msgsz = sizeof(mensaje) - sizeof(long);

        int count_muertos = 0;
        for (int i = 0; i < K; i++){
            if (msgrcv(msqid, &mensaje, msgsz, 0, 0) == -1){
                perror ("Error en msgrcv()");
            }
            //printf("PADRE: pid: %d estado= %s\n", mensaje.pid, mensaje.estado);


            if (strcmp(mensaje.estado, "KO") == 0){
                kill(mensaje.pid, SIGTERM);
                wait(NULL);
                //printf("ha muerto %d \n", mensaje.pid); fflush(stdout);
                count_muertos++;
                //Pone el PID muerto a "0" en la lista
                wait_sem(semid);
                for (int i = 0; i < N; i++){
                    if (lista[i] == mensaje.pid) lista[i] = 0;
                }
                signal_sem(semid);
            }
        }
        K -= count_muertos; //se reduce el nº de procesos vivos

    }while(K > 1);

    //FIN DE LAS RONDAS

    //abrimos el fichero FIFO para escribir el resultado
    int fd_FIFO = open(FIFO_PATH, O_WRONLY);
    if (fd_FIFO == -1){
        perror ("Error al abrir el FIFO");
        exit(EXIT_FAILURE);
    }


    if (K == 1){
        //Si solo queda 1 proceso hijo, lo matamos
        for (int i = 0; i < N; i++){
            wait_sem(semid);
            if (lista[i] != 0){
                kill(lista[i], SIGTERM);
                wait(NULL);
                char mensaje [40];
                sprintf(mensaje, "El hijo %d ha ganado\n", lista[i]);
                if (write(fd_FIFO, mensaje, strlen(mensaje)) == -1){
                    perror("Error al escribir en el fichero FIFO");
                    close(fd_FIFO);
                    exit(EXIT_FAILURE);
                }
            }
            signal_sem(semid);
        }

    }else if (K == 0){
        //se han matado todos los procesos simultaneamente
        //printf("Empate\n");
        if (write(fd_FIFO, "Empate\n", strlen("Empate\n")) == -1){
            perror("Error al escribir en el fichero FIFO");
            close(fd_FIFO);
            exit(EXIT_FAILURE);
        }
    }else{
        //Error, punto de codigo inalcanable
    }

    //Liberar todos los recursos IPC
    //Eliminar cola de mensajes
    if (msgctl(msqid, IPC_RMID, NULL) == -1){
        perror("Error en msgctl()");
    }
    //Eliminar segmento memoria compartida
    if (shmdt(lista) == -1){
        perror("Error en shmdt()");
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1){
        perror ("Error en shmctl()");
    }

    //Eliminacion del semaforo
    if (semctl(semid, IPC_RMID, 0) == -1){
        perror ("Error en semctl()");
    }

    //Cerrar fichero de tuberia
    close(pipefd[1]);

    //cerrar fichero FIFO
    close(fd_FIFO);

    //Mostrar comprobacion de liberacion de recursos
    system("ipcs -q");  //muestra las colas de mensajes
    system("ipcs -s");  //muestra semaforos

    return 0;
}
