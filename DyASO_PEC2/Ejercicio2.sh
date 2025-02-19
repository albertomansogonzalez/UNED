#!/bin/bash
#este archivo es un scrip que:
#1 compila los fuentes padre.c e hijo.c con gcc
#2 crea el fihero fifo "resultado"
#lanza un cat en segundo plano para leer "resultado" 
#lanza el proceso padre
#al acabar limpia todos los ficheros que ha creado


#compila los fuentes
gcc -g Trabajo2/padre.c -o PADRE
gcc -g Trabajo2/hijo.c -o HIJO

#crea el fichero FIFO "resultado"
mkfifo "resultado"

if [ $? -ne 0 ]; then
	echo "Error en Ejercicio2.sh al crear el FIFO con mkfifo"
	exit 1
fi

#lanzar cat en segundo plano para leer "resultado"
cat resultado &

#lanzar el proceso padre
./PADRE X 10

#borrar todos los archivos ejecutables y el fichero FIFO
rm PADRE HIJO resultado
