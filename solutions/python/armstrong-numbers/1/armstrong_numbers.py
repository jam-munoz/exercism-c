def digit_count(number: int) -> int:
    if number < 10:
        return 1
    elif number < 100:
        return 2
    elif number < 1000:
        return 3
    elif number < 10000:
        return 4
    elif number < 100000:
        return 5
    elif number < 1000000:
        return 6
    elif number < 10000000:
        return 7
    elif number < 100000000:
        return 8
    elif number < 1000000000:
        return 9
    else:
        return 10

def is_armstrong_number(number: int) -> bool:
    digits = digit_count(number)
    digit_sum = 0
    num = number
    while num > 0:
        digit_sum += (num % 10) ** digits
        num //= 10
    return digit_sum == number
