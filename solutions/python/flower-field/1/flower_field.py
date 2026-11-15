MINE = 0x2A
SPACE = 0x20
ONE = 0x31
NINE = 0x39

def annotate(garden):
    if not garden:
        return []
    mines = [bytearray(i.encode('ascii')) for i in garden]
    y = len(garden)
    x = len(garden[0])
    for i in range(y):
        if x != len(mines[i]):
            raise ValueError("The board is invalid with current input.")
        for j in range(x):
            if mines[i][j] == MINE:
                top = i - 1
                left = j - 1
                right = j + 1
                bottom = i + 1
                if left < 0:
                    left += 1
                if right == x:
                    right -= 1
                if top >= 0:
                    for k in range(left, right + 1):
                        if mines[top][k] == SPACE:
                            mines[top][k] = ONE
                        elif ONE <= mines[top][k] <= NINE:
                            mines[top][k] += 1
                        elif mines[top][k] > NINE:
                            raise ValueError("The board is invalid with current input.")
                for k in range(left, right + 1):
                    if mines[i][k] == SPACE:
                        mines[i][k] = ONE
                    elif ONE <= mines[i][k] <= NINE:
                        mines[i][k] += 1
                    elif mines[i][k] > NINE:
                        raise ValueError("The board is invalid with current input.")
                if bottom < y:
                    for k in range(left, right + 1):
                        if mines[bottom][k] == SPACE:
                            mines[bottom][k] = ONE
                        elif ONE <= mines[bottom][k] <= NINE:
                            mines[bottom][k] += 1
                        elif mines[bottom][k] > NINE:
                            raise ValueError("The board is invalid with current input.")
            elif mines[i][j] != SPACE and (mines[i][j] < ONE or NINE < mines[i][j]):
                raise ValueError("The board is invalid with current input.")
    return [out.decode('ascii') for out in mines]