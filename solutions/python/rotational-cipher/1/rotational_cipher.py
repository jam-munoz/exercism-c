def rotate(text, key):
    key = key % 26
    n = len(text)
    arr = [0] * len(text)
    for i in range(n):
        arr[i] = ord(text[i])
    for i in range(n):
        if 65 <= arr[i] <= 90:
            arr[i] = arr[i] + key
            if arr[i] > 90:
                arr[i] -= 26
            elif arr[i] < 65:
                arr[i] += 26
        if 97 <= arr[i] <= 122:
            arr[i] = arr[i] + key
            if arr[i] > 122:
                arr[i] -= 26
            elif arr[i] < 97:
                arr[i] += 26
    return "".join(chr(c) for c in arr)
