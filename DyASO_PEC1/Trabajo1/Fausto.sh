#!/bin/bash

#Recibe órdenes creando los procesos y listas adecuadas
#Si el Demonio no está vivo lo crea
#Al leer/escribir en las listas hay que usar bloqueo para no coincidir con el Demonio



#Comprobar la existencia de un proceso Demonio en ejecucion.
if ! pgrep -x "Demonio.sh" > /dev/null ; then

	#Reiniciar todas las estructuras, la Biblia y lanzar un proceso Demonio
		#borrar ficheros: procesos, procesos_servicio, procesos_periodicos, Biblia.txt, Apocalipsis y San Pedro, y carpeta Infierno
		rm -f Biblia.txt
		rm -f procesos
		rm -f procesos_servicio
		rm -f procesos_periodicos
		rm -f -r infierno

		#vovler a crear los ficheros y carpetas, excepto Apocalipsis
		touch Biblia.txt
		touch procesos
		touch procesos_servicio
		touch procesos_periodicos
		mkdir infierno
		touch SanPedro

		#lanzar proceso Demonio
		nohup './Demonio.sh' /dev/null > /dev/null 2>&1 &

		#Escribir entrada en la biblia indicando la hora de creacion
		HORA_ACTUAL=$(date +%H:%M:%S)
		echo "$HORA_ACTUAL -------Genesis----------" > Biblia.txt
		echo "$HORA_ACTUAL El demonio ha sido creado" >> Biblia.txt
fi

#Ejecucion de comandos
#run, run-service, list, help, stop y end

if [ "$#" -eq 0 ]; then
	echo "Comando no proporcionado. Usar \"./Fasuto.sh help\" para ver el uso correcto"
	exit 1
fi

case $1 in
	run)
		if [ "$#" -ne 2 ]; then
			echo "Argumentos erroneos. Usar \"./Fausto.sh help\" para ver el uso correcto"
			exit 1
		fi
		bash -c "$2" &
		flock SanPedro echo "$! '$2'" >> procesos
		echo "$(date +%H:%M:%S) El proceso $! '$2' ha nacido." >> Biblia.txt
	;;
	run-service)
		if [ "$#" -ne 2 ]; then
			echo "Argumentos erroneos. Usar \"./Fausto.sh help\" para ver el uso correcto"
			exit 1
		fi
		bash -c "$2" &
		flock SanPedro echo "$! '$2'" >> procesos_servicio
		echo "$(date +%H:%M:%S) El proceso $! '$2' ha nacido." >> Biblia.txt
	;;
	run-periodic)
		if [ "$#" -ne 3 ]; then
			echo "Argumentos erroneos. Usar \"./Fausto.sh help\" para ver el uso correcto"
			exit 1
		fi
		bash -c "$3" &
		flock SanPedro echo "0 $2 $! '$3'" >> procesos_periodicos
		echo "$(date +%H:%M:%S) El proceso $! '$3' ha nacido." >> Biblia.txt
	;;
	list)
		if [ "$#" -ne 1 ]; then
			echo "Argumentos erroneos. Usar \"./Fausto.sh help\" para ver el uso correcto"
			exit 1
		fi
		echo "------- Contenido fichero procesos -------"
		flock SanPedro cat procesos
		echo "------- Contenido fichero procesos_servicio -------"
		flock SanPedro cat procesos_servicio
		echo "------ Contenido fichero procesos_periodicos ------"
		flock SanPedro cat procesos_periodicos
	;;
	help)
		echo
		echo "Uso: ./Fausto.sh [OPTION]"
		echo "Si el demonio no esta invocado, Fausto lo invoca y reinicia los ficheros: procesos, procesos_servicio, procesos_periodicos, Biblita.txt, Apocalipsis y SaPedro, asi como la carpeta Infierno"
		echo "Ademas tambien permite los siguientes comandos:"
		echo
		echo "	run [comando]			Ejecutar un comando una sola vez"
		echo "	run-service [comando]		Ejecutar comando como servicio"
		echo "	run-periodic [T]  [comando]	Ejecutar comando con reinicio de periodo T"
		echo "	list				Mostrar el contenido de las listas: procesos, procesos_servicio y procesos_periodicos"
		echo "	help				Muestra el panel de ayuda"
		echo "	stop [PID]			Indica al demonio que debe destruir el proceso"
		echo "	end				Inicia el Apocalipsis"
	;;
	stop)
		if [ "$#" -ne 2 ]; then
			echo "Argumentos erroneos. Usar \"./Fausto.sh help\" para ver el uso correcto"
			exit 1
		fi
		#buscar PID en las listas
		./Fausto.sh list | grep $2 > /dev/null 2>&1
		if [ $? -eq 0 ]; then
			#si encuentra el PID, crea un fichero en la carpeta infierno con el nombre del PID
			touch ./infierno/$2
		else
			echo "no encontrado PID='$2'. Usar ./Fausto.sh list para obtener la lista de procesos"
		fi

	;;
	end)
		if [ "$#" -ne 1 ];then
			echo "Argumentos erroneos. Usar \"./Fausto help\" para ver el uso correcto"
			exit 1
		fi
		#Crear fichero llamado Apocalipsis para que el Demonio lo inicie
		touch Apocalipsis
	;;
	*)
		echo "Comando no reconocido. Usar \"./Fausto help\" para ver los comandos correctos"
		exit 1
	;;
esac

