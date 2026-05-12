from tableroadaptativo import Tablero
from reina import Reina
from torre import Torre

#El tablero dado y el peon no cumplen con lo que dicen las reglas
#el peon no utiliza tablero.filas y tablero.cols, hardcodeado a 8
#tablero (el normal) no tiene parametros filas y cols
#por eso uso el tablero m x n que hice yo

#inicialización tableros y piezas (está en formato filas x columnas)
tablero = Tablero(8,8)
reina = Reina("blanco")

#prueba 1:
tablero.colocar_pieza(reina,4,3)
tablero.mostrar_movimientos(reina)

#prueba 2:

torre = Torre("blanco")
torre_enemiga = Torre("negra")

tablero.colocar_pieza(torre,3,2)
tablero.colocar_pieza(torre,2,3)
tablero.colocar_pieza(torre_enemiga,5,3)
tablero.colocar_pieza(torre_enemiga,4,5)
tablero.mostrar_movimientos(reina)