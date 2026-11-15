def roman(number):
    cm = cd = xc = xl = ix = iv = 0
    if number % 10 == 4:
        iv = 1
        number -= 4
    if number % 10 == 9:
        ix = 1
        number -= 9
    if (number // 10) % 10 == 4:
        xl = 1
        number -= 40
    if (number // 10) % 10 == 9:
        xc = 1
        number -= 90
    if (number // 100) % 10 == 4:
        cd = 1
        number -= 400
    if (number // 100) % 10 == 9:
        cm = 1
        number -= 900
    m = number // 1000
    number %= 1000
    d = number // 500
    number %= 500
    c = number // 100
    number %= 100
    l = number // 50
    number %= 50
    x = number // 10
    number %= 10
    v = number // 5
    i = number % 5
    return "M" * m + "CM" * cm + "D" * d + "CD" * cd + "C" * c + "XC" * xc + "L" * l + "XL" * xl + "X" * x + "IX" * ix + "V" * v + "IV" * iv + "I" * i