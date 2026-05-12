class Tablero:
    _BLANCA = "\033[47m"   # fondo blanco
    _NEGRA  = "\033[100m"  # fondo gris oscuro
    _VERDE  = "\033[42m"   # fondo verde (movimiento posible)
    _RESET  = "\033[0m"

    def __init__(self, filas, cols):
        #es el mismo tablero de antes, solo que toqué lo de filas y columnas, si falla otra cosa no viene de mi parte xd
        self.cols = cols
        self.filas = filas
        self._grid = [[None] * cols for i in range(filas)]
        self._marcadas = set()  
        
    def _color_casilla(self, fila, columna):
        if (fila + columna) % 2 == 0:
            return self._BLANCA
        return self._NEGRA
    

    def hay_enemigo(self, fila, col, color_amigo):
        """Retorna True si la celda tiene una pieza de color distinto."""
        pieza = self._grid[fila][col]
        return pieza is not None and pieza.color != color_amigo

    def mostrar_movimientos(self, pieza):
        """Pide a la pieza sus movimientos, los marca y muestra el tablero."""
        self._marcadas = set(pieza.movimientos_posibles(self))
        self.imprimir()
        self._marcadas = set()

    def celda_libre(self, fila, col):
        return self._grid[fila][col] is None
    
    def colocar_pieza(self, pieza, fila, col):
        self._grid[fila][col] = pieza
        pieza._fila = fila
        pieza._col  = col

    def imprimir(self):
        letras = "abcdefghijklmnopqrstuvxyz"
        letrastablero = "    "
        for i in range(self.cols):
            letrastablero += letras[i]
            if i != self.cols - 1:
                letrastablero += "   "
        print(f"\n{letrastablero}")
        print("  +" + "---+" * self.cols)
        for fila in range(self.filas):
            if self.filas - fila < 10:
                print(f"{self.filas - fila} |", end="")
            else:
                print(f"{self.filas - fila}|", end="")
            for col in range(self.cols):
                pieza   = self._grid[fila][col]
                simbolo = str(pieza) if pieza else " "
                fondo   = self._VERDE if (fila, col) in self._marcadas else self._color_casilla(fila, col)
                fondo = fondo.replace("m", ";91m")
                print(f"{fondo} {simbolo} {self._RESET}|", end="")
            print(f" {self.filas - fila}")
        print("  +" + "---+" * self.cols)
        print(f"{letrastablero}\n")
