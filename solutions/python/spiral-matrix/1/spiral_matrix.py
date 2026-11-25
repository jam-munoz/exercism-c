def spiral_matrix(size):
    matrix = [[0] * size for i in range(size)]

    x = y = start = 0
    i = 1
    while start < size:
        while x < size:
            matrix[y][x] = i
            i += 1
            x += 1
        x -= 1
        y += 1
        while y < size:
            matrix[y][x] = i
            i += 1
            y += 1
        y -= 1
        x -= 1
        while x >= start:
            matrix[y][x] = i
            i += 1
            x -= 1
        x += 1
        y -= 1
        while y > start:
            matrix[y][x] = i
            i += 1
            y -= 1
        y += 1
        x += 1
        start += 1
        size -= 1            
    return matrix
