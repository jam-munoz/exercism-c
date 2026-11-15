class Digits:
    ZERO = [" _ ", "| |", "|_|", "   "]
    ONE = ["   ", "  |", "  |", "   "]
    TWO = [" _ ", " _|", "|_ ", "   "]
    THREE = [" _ ", " _|", " _|", "   "]
    FOUR = ["   ", "|_|", "  |", "   "]
    FIVE = [" _ ", "|_ ", " _|", "   "]
    SIX = [" _ ", "|_ ", "|_|", "   "]
    SEVEN = [" _ ", "  |", "  |", "   "]
    EIGHT = [" _ ", "|_|", "|_|", "   "]
    NINE = [" _ ", "|_|", " _|", "   "]

def read_block(input_grid):
    blocks = [
        [row[c:c+3] for row in input_grid]
        for c in range(0, len(input_grid[0]), 3)
    ]
    digits = len(blocks)
    number = []
    for i in range(digits):
        match blocks[i]:
            case Digits.ZERO:
                number.append("0")
            case Digits.ONE:
                number.append("1")
            case Digits.TWO:
                number.append("2")
            case Digits.THREE:
                number.append("3")
            case Digits.FOUR:
                number.append("4")
            case Digits.FIVE:
                number.append("5")
            case Digits.SIX:
                number.append("6")
            case Digits.SEVEN:
                number.append("7")
            case Digits.EIGHT:
                number.append("8")
            case Digits.NINE:
                number.append("9")
            case _:
                number.append("?")
    return "".join(number)

def convert(input_grid):
    if not input_grid:
        return ""
    if len(input_grid) % 4 != 0:
        raise ValueError("Number of input lines is not a multiple of four")
    for i in range(len(input_grid)):
        if len(input_grid[i]) % 3 != 0:
            raise ValueError("Number of input columns is not a multiple of three")
    blocks = [input_grid[r:r+4] for r in range(0, len(input_grid), 4)]
    lst = []
    for i in range(len(blocks)):
        lst.append(read_block(blocks[i]))
    return ",".join(lst)
