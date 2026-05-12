class Alfil:
    def __init__(self, color):
        self._fila = None
        self._col = None
        self.color = color
        self._movido = False
        # self.id = id

    def __str__(self):
        return "♗" if self.color == "blanco" else "♝"
    
    #def __repr__(self):
    #    return f"Peon {self.color}"
    
    def movimientos_posibles(self, tablero):
        """Retorna lista de (fila, col) a los que puede moverse."""
        movs      = []
        direcciones_alfil = [(-1,1), (-1,-1), (1,1), (1,-1)]
        #esto es lo que dije en torre, con tuplas, sale más corto xd
        f, c      = self._fila, self._col
        for movimientos in direcciones_alfil:
            n_fila = f + movimientos[0]
            n_cols = c + movimientos[1]

            while 0 <= n_fila < tablero.filas and 0 <= n_cols < tablero.cols:
                if tablero.celda_libre(n_fila,n_cols):
                    movs.append((n_fila,n_cols))
                else:
                    if tablero.hay_enemigo(n_fila,n_cols, self.color):
                        movs.append((n_fila, n_cols))
                    break
                n_fila += movimientos[0]
                n_cols += movimientos[1]
        return movs