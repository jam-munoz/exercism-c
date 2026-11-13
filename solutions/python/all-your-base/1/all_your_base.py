def rebase(input_base, digits, output_base):
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if output_base < 2:
        raise ValueError("output base must be >= 2")
    if not digits:
        return [0]
    decimal_number = 0
    for i in range(len(digits)):
        if digits[-1 - i] < 0 or digits[-1 - i] >= input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")
        decimal_number += digits[-1 - i] * (input_base ** i)
    if decimal_number == 0:
        return [0]
    n = decimal_number
    digits = 0
    while n > 0:
        n //= output_base
        digits += 1
    arr = [0] * digits
    for i in range(digits):
        arr[-1 - i] = decimal_number % output_base
        decimal_number //= output_base
    return arr
