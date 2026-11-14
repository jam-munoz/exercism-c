def commands(binary_str):
    code = int(binary_str, 2)
    lst = []
    if code & 0x1:
        lst.append("wink")
    if code & 0x2:
        lst.append("double blink")
    if code & 0x4:
        lst.append("close your eyes")
    if code & 0x8:
        lst.append("jump")
    if code & 0x10:
        lst.reverse()
    return lst