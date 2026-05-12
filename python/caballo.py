class Caballo:
    def __init__(self, color):
        self._fila = None
        self._col = None
        self.color = color
        self._movido = False
        # self.id = id

    def __str__(self):
        return "♘" if self.color == "blanco" else "♞"
    
    #def __repr__(self):
    #    return f"Peon {self.color}"
    
    def movimientos_posibles(self, tablero):
        """Retorna lista de (fila, col) a los que puede moverse."""
        movs      = []
        #esto estaba en la guía
        direcciones_caballo = [(-1,-2),(1,2),(-1,2),(1,-2), (-2,-1),(2,1),(-2,1),(2,-1)]
        f, c      = self._fila, self._col
        for movimientos in direcciones_caballo:
            n_fila = f + movimientos[0]
            n_cols = c + movimientos[1]

            if (0 <= n_fila < tablero.filas and 0 <= n_cols < tablero.cols) and tablero.celda_libre(n_fila,n_cols):
                movs.append((n_fila,n_cols))
            elif (0 <= n_fila < tablero.filas and 0<= n_cols < tablero.cols) and tablero.hay_enemigo(n_fila,n_cols, self.color):
                movs.append((n_fila, n_cols))
        return movs