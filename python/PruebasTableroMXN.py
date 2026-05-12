from tableroadaptativo import Tablero
from torre import Torre
from alfil import Alfil

#El tablero dado y el peon no cumplen con lo que dicen las reglas
#el peon no utiliza tablero.filas y tablero.cols, hardcodeado a 8
#tablero (el normal) no tiene parametros filas y cols
#por eso uso el tablero m x n que hice yo

#inicialización tableros y piezas (está en formato filas x columnas)
tablero_1 = Tablero(5,10)
torre = Torre("blanco")

tablero_2 = Tablero(10,5)
alfil = Alfil("blanco")

#prueba 1

tablero_1.colocar_pieza(torre, 2, 4)
tablero_1.mostrar_movimientos(torre)

#prueba 2

tablero_2.colocar_pieza(alfil,5,2)
tablero_2.mostrar_movimientos(alfil)