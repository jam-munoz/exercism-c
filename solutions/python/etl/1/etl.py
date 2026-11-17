def transform(legacy_data):
    D = {}
    alph = "abcdefghijklmnopqrstuvwxyz"
    for letter in alph:
        for number in legacy_data:
            if letter.upper() in legacy_data[number]:
                D[letter] = number
    return D
