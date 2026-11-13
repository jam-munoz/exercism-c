def is_valid(isbn):
    arr = [0] * 10
    i = 0
    for j in range(len(isbn) - 1):
        if isbn[j].isdigit():
            if i == 10:
                return False
            arr[i] = int(isbn[j])
            i += 1
        elif isbn[j] != '-':
            return False
    if i != 9:
        return False
    if isbn[-1] == 'X':
        arr[i] = 10
    elif isbn[-1].isdigit():
        arr[i] = int(isbn[-1])
    else:
        return False
    return (arr[0] * 10 + arr[1] * 9 + arr[2] * 8 + arr[3] * 7 + arr[4] * 6 + arr[5] * 5 + arr[6] * 4 + arr[7] * 3 + arr[8] * 2 + arr[9]) % 11 == 0
