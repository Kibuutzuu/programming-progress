from tableroadaptativo import Tablero
from alfil import Alfil
from torre import Torre

#El tablero dado y el peon no cumplen con lo que dicen las reglas
#el peon no utiliza tablero.filas y tablero.cols, hardcodeado a 8
#tablero (el normal) no tiene parametros filas y cols
#por eso uso el tablero m x n que hice yo

#inicialización tablero y pieza
tablero = Tablero(8,8)
alfil = Alfil("blanco")

#prueba 1:
tablero.colocar_pieza(alfil,4,4)
tablero.mostrar_movimientos(alfil)

#prueba 2:

torre = Torre("blanco")
tablero.colocar_pieza(torre,3,3)
tablero.mostrar_movimientos(alfil)

#prueba 3:

torre_negra = Torre("negra")
tablero.colocar_pieza(torre_negra,3,5)
tablero.mostrar_movimientos(alfil)