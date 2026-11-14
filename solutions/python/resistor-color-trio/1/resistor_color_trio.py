def color_code(color):
    match color:
        case "black":
            return 0
        case "brown":
            return 1
        case "red":
            return 2
        case "orange":
            return 3
        case "yellow":
            return 4
        case "green":
            return 5
        case "blue":
            return 6
        case "violet":
            return 7
        case "grey":
            return 8
        case "white":
            return 9
    return -1

def label(colors):
    ohm = 0
    for i in range(2):
        ohm = ohm * 10 + color_code(colors[i])
    mul = color_code(colors[2])
    if mul == 9:
        prefix = "giga"
        mul = 0
    elif mul > 5:
        prefix = "mega"
        mul -= 6
    elif mul > 2:
        prefix = "kilo"
        mul -= 3
    else:
        prefix = ""
    ohm *= 10 ** mul
    if ohm > 999:
        ohm //= 1000
        prefix = "kilo"
    return f"{ohm} {prefix}ohms"
