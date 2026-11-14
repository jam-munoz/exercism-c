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

def color_tolerance(color):
    match color:
        case "grey":
            return .05
        case "violet":
            return .1
        case "blue":
            return .25
        case "green":
            return .5
        case "brown":
            return 1
        case "red":
            return 2
        case "gold":
            return 5
        case "silver":
            return 10
    return 20

def resistor_label(colors):
    if len(colors) < 3:
        return "0 ohms"
    ohm = 0
    prefixes = ["", "kilo", "mega", "giga"]
    for i in range(len(colors) - 2):
        ohm = ohm * 10 + color_code(colors[i])
    mul = color_code(colors[-2])
    if mul == 9:
        prefix = 3
        mul = 0
    elif mul > 5:
        prefix = 2
        mul -= 6
    elif mul > 2:
        prefix = 1
        mul -= 3
    else:
        prefix = 0
    ohm *= 10 ** mul
    if ohm > 999:
        ohm /= 1000
        prefix += 1
    return f"{ohm:g} {prefixes[prefix]}ohms ±{color_tolerance(colors[-1])}%"
