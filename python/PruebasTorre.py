from tableroadaptativo import Tablero
from torre import Torre
from alfil import Alfil
#voy a poner el siguiente comentario en todas las pruebas:
#El tablero dado y el peon no cumplen con lo que dicen las reglas
#el peon no utiliza tablero.filas y tablero.cols, hardcodeado a 8
#tablero (el normal) no tiene parametros filas y cols
#por eso uso el tablero m x n que hice yo

#inicialización tablero y pieza
tablero = Tablero(8,8)
torre = Torre("blanco")

#coloco la pieza en lo que YO considero la mitad del tablero 8x8
tablero.colocar_pieza(torre, 4, 4)
#prueba 1:
tablero.mostrar_movimientos(torre)

#prueba 2:
alfil = Alfil("blanco")
tablero.colocar_pieza(alfil, 4, 5)
tablero.mostrar_movimientos(torre)

#prueba 3:
alfil_negro = Alfil("negro")
tablero.colocar_pieza(alfil_negro,3,4)
tablero.mostrar_movimientos(torre)
