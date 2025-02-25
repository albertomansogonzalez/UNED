#!/bin/bash

# cada 1 segundo, lee las listas y revive los procesos cuando sea necesario dejando entradas en la biblia
# con el Apocalipsis: terminar todos los procesos y limpiar todo dejando solo Fausto, el Demonio y la Biblia

while true; do
	sleep 1

	#comprobar si llega el apocalipsis
	if [ -e "Apocalipsis" ]; then

		echo "$(date +%H:%M:%S) ---------------Apocalipsis---------------" >> Biblia.txt
	fi

	#recorrer todas las listas para llevar a cabo las acciones oportunas
	touch /tmp/archivo_tmp	#este fichero sirve de buffer para las nuevas listas actualizadas (quitando los procesos que corresponda) para no hacer borrado in-file
	> /tmp/archivo_tmp

	#Recorrer lista procesos
	while read linea; do
		PID=$(echo -n $linea | cut -d ' ' -f1)

		#el PID se encuentra en el directorio infierno/ ?
		if [ -f infierno/$PID ] || [ -f "Apocalipsis" ]; then
			#no lo incluimos en la nueva lista

			#eliminar el fichero del infierno
			rm infierno/$PID
			#aniadir entrada en la Biblia
			echo "$(date +%H:%M:%S) El proceso $linea ha terminado" >> Biblia.txt
			#terminar todo el arbol del proceso
			pstree -p $PID | grep -o '([0-9]\+)' | grep -o '[0-9]\+' | xargs kill -SIGTERM
		else
			#si no sigue activo, lo elimina de la lista
			ps -p $PID > /dev/null
			if [ $? -eq 1 ];then
				#no lo incluimos en la nueva lista, ya que el proceso esta terminado
				#tambien aniadimos entrada en la Biblia
				echo "$(date +%H:%M:%S) El proceso $linea ha terminado" >> Biblia.txt
			else
				#si el PID no esta en el infinero, y sigue activo, debe seguir en la lista
				echo $linea >> /tmp/archivo_tmp
			fi
		fi
	done < "procesos"
	#actulizamos la nueva lista
	flock SanPedro mv /tmp/archivo_tmp procesos
	> /tmp/archivo_tmp

	#Recorrer lista procesos_servicio
	while read linea; do
		PID=$(echo -n $linea | cut -d ' ' -f1)

		#¿el PID se encuentra en el direcorio infierno/ ?
		if [ -f infierno/$PID ] || [ -f "Apocalipsis" ]; then
			#no lo incluimos en la nueva lista
			#eliminar el fichero del infierno
			rm infierno/$PID
			#aniadir entrada en la Biblia
			echo "$(date +%H:%M:%S) El proceso $linea ha terminado" >> Biblia.txt
			#terminar todo el arbol de proceso
			pstree -p $PID | grep -o '([0-9]\+)' | grep -o '[0-9]\+' | xargs kill -SIGTERM
		else
			echo "el archivo $PID no esta en el infierno"
			#si no sigue activo, se resucita
			ps -p $PID > /dev/null
			if [ $? -eq 1 ];then
				#lo resucitamos
				comando=$(echo -n $linea | cut -d "'" -f2)
				bash -c "$comando" &
				nuevo_PID=$!
				#modificar entrada en lista procesos_servicio
				echo $linea | sed "s/$PID/$nuevo_PID/" >> /tmp/archivo_tmp
				#aniadir entrada en la Biblia
				echo "$(date +%H:%M:%S) El proceso $linea resucita con pid $nuevo_PID" >> Biblia.txt
			else
				#si el proceso no esta en el infierno, y sigue activo. no se hace nada
				echo $linea >> /tmp/archivo_tmp
			fi
		fi
 	done < "procesos_servicio"
	#actualizamos la nueva lista
	flock SanPedro mv /tmp/archivo_tmp procesos_servicio
	> /tmp/archivo_tmp

	#Recorrer lista procesos_periodico
	while read linea; do
		PID=$(echo -n $linea | cut -d ' ' -f3)

		#¿el PID se encuentra en el infierno?
		if [ -f infierno/$PID ] || [ -f "Apocalipsis" ]; then
			#no lo incluimos en la nueva lista
			#eliminar fichero del infierno
			rm infierno/$PID
			#aniadir entrada en la Biblia
			comando=$(echo -n $linea | cut -d "'" -f2)
			echo "$(date +%H:%M:%S) El proceso $PID \"comando\" ha terminado" >> Biblia.txt
			#terminar todo el arbol de proceso
			pstree -p $PID | grep -o '([0-9]\+)' | grep -o '[0-9]\+' | xargs kill -SIGTERM
		else
			#incrementar el contador de tiempo
			contador=$(echo -n $linea | cut -d ' ' -f1)
			let contador+=1
			#si no sigue activo, se resucita
			ps -p $PID > /dev/null
			if [ $? -eq 1 ];then
				#lo resucitamos si t>=T
				tiempo=$(echo $linea | cut -d ' ' -f1)
				T=$(echo $linea | cut -d ' ' -f2)
				if [ $tiempo -ge $T ];then
					comando=$(echo -n $linea | cut -d "'" -f2)
					bash -c "$comando" &
					nuevo_PID=$!
					#modificamos entrada en proceos_periodico, volvemos a tiempo=0
					echo $linea | sed "s/^[^ ]*/0/" | sed "s/$PID/$nuevo_PID/" >> /tmp/archivo_tmp
					#aniadir entrada en la Biblia
					echo "$(date +%H:%M:%S) El proceso $PID \"$comando\" se ha reencarnado en el pid $nuevo_PID" >> Biblia.txt
				else
					echo $linea | sed "s/^[^ ]*/$contador/" >> /tmp/archivo_tmp
				fi
			else
				#si el proceso no esta en el infierno, y ademas sigue activo, solo actualizar el contador
				echo $linea | sed "s/^[^ ]*/$contador/" >> /tmp/archivo_tmp
			fi
		fi
	done < procesos_periodicos
	#actualizamos la nueva lista, quitando el fichero temporal
	flock SanPedro mv /tmp/archivo_tmp procesos_periodicos

	#si llega el Apocalipsis, tenemos que borrar todos los ficheros excepto la Biblia
	if [ -f "Apocalipsis" ];then
		rm procesos
		rm procesos_periodicos
		rm procesos_servicio
		rm Apocalipsis
		rm -r infierno
		rm SanPedro
		echo "$(date +%H:%M:%S) Se acabo el mundo." >> Biblia.txt
		exit 0;
	fi

done
