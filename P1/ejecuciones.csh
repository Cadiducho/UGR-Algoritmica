#!/bin/csh
@ inicio = 100
@ fin = 1000000
@ incremento = 100
@ i = $inicio
echo > tiempos.dat
while ( $i <= $fin )
 echo Ejecución tam = $i
 echo `./busqueda_lineal $i 10000` >> tiempos.dat
 @ i += $incremento
end
