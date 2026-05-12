class Torre:
    def __init__(self, color):
        self._fila = None
        self._col = None
        self.color = color
        self._movido = False
        # self.id = id

    def __str__(self):
        return "♖" if self.color == "blanco" else "♜"
    
    #def __repr__(self):
    #    return f"Peon {self.color}"
    
    def movimientos_posibles(self, tablero):
        """Retorna lista de (fila, col) a los que puede moverse."""
        movs      = []
        direccionarribayabajo = [-1,1]
        direccionizqyder = [-1,1] #esto para la reina yo cacho que lo voy a hacer junto, porque así me parece muy confuso
        #y supongo que el alfil cuando lo empiece tendrá la misma lógica pero onda (-1,-1), (-1,1) y asi, pero, ahí voy viendo a medida que lo haga
        #porque nica lo hago con listas separadas, me sale más a cuenta tuplas para ahorrarme lo que voy a hacer ahora
        f, c      = self._fila, self._col
        #no me gustó la nomenclatura de dc, nc, entiendo que es direccion en c y nueva c pero no me gustó asi que ahora será n_fila y n_col para entenderlo
        for movimientoarribajo in direccionarribayabajo:
            n_fila = f + movimientoarribajo
            while 0 <= n_fila < tablero.filas:
                if tablero.celda_libre(n_fila, self._col):
                    movs.append((n_fila, self._col))
                else:
                    if tablero.hay_enemigo(n_fila,self._col,self.color):
                        movs.append((n_fila,self._col))
                    break
                n_fila += movimientoarribajo

        for movimientoderizq in direccionizqyder:
            n_col = c + movimientoderizq
            while 0 <= n_col < tablero.cols:
                if tablero.celda_libre(self._fila, n_col):
                    movs.append((self._fila, n_col))
                else:
                    if tablero.hay_enemigo(self._fila, n_col, self.color):
                        movs.append((self._fila,n_col))
                    break
                n_col += movimientoderizq


        return movs