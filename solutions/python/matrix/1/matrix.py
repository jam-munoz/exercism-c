class Matrix:
    def __init__(self, matrix_string):
        self.x = [[int(x) for x in line.split()] for line in matrix_string.split('\n')]
        self.y = [list(fila) for fila in zip(*self.x)]

    def row(self, index):
        return self.x[index - 1]

    def column(self, index):
        return self.y[index - 1]
