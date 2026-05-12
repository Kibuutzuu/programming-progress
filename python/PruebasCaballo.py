from tableroadaptativo import Tablero
from caballo import Caballo
from torre import Torre

#El tablero dado y el peon no cumplen con lo que dicen las reglas
#el peon no utiliza tablero.filas y tablero.cols, hardcodeado a 8
#tablero (el normal) no tiene parametros filas y cols
#por eso uso el tablero m x n que hice yo

#inicialización tableros y piezas (está en formato filas x columnas)
tablero = Tablero(8,8)
caballo = Caballo("blanco")

#prueba 1:

tablero.colocar_pieza(caballo,4,5)
tablero.mostrar_movimientos(caballo)

#prueba 2:
caballo2 = Caballo("blanco")
tablero.colocar_pieza(caballo2,7,0)
tablero.mostrar_movimientos(caballo2)

#prueba 3:
#caballo rodeado pero pasando por encima para atacar
torre = Torre("blanco")
tablero.colocar_pieza(torre,1,1)
tablero.colocar_pieza(torre,1,2)
tablero.colocar_pieza(torre,1,3)
tablero.colocar_pieza(torre,2,1)
tablero.colocar_pieza(torre,3,1)
tablero.colocar_pieza(torre,3,2)
tablero.colocar_pieza(torre,3,3)
tablero.colocar_pieza(torre,2,3)

caballo3 = Caballo("blanco")

tablero.colocar_pieza(caballo3, 2,2)

caballo_negro = Caballo("negro")
tablero.colocar_pieza(caballo_negro, 0,1)

tablero.mostrar_movimientos(caballo3)