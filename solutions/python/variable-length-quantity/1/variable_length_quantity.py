def encode(numbers):
    out = []
    for number in reversed(numbers):
        first = True
        while number > 0 or first:
            out.append(number & 0x7f if first else number & 0x7f | 0x80)
            number >>= 7
            first = False
    out.reverse()
    return out

def decode(bytes_):
    out = []
    number = 0
    for byte in bytes_:
        number <<= 7
        number += byte & 0x7f
        if byte < 0x80:
            out.append(number)
            number = 0
    if number > 0 or len(out) == 0:
        raise ValueError("incomplete sequence")
    return out
