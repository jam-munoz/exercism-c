def rows(letter):
    if letter == 'A':
        return ['A']
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    n = alphabet.index(letter)
    i = 0
    diamond = []
    #upper section
    while i < n:
        row = []
        row.extend([' '] * (n - i))
        row.append(alphabet[i])
        row.append(' ' * (2 * i - 1))
        if i != 0:
            row.append(alphabet[i])
        row.append(' ' * (n - i))
        diamond.append(''.join(row))
        i += 1
    #middle section
    row = []
    row.append(alphabet[i])
    row.append(' ' * (2 * n - 1))
    row.append(alphabet[i])
    #lower section
    while i >= 0:
        row = []
        row.extend([' '] * (n - i))
        row.append(alphabet[i])
        row.append(' ' * (2 * i - 1))
        if i != 0:
            row.append(alphabet[i])
        row.extend([' '] * (n - i))
        diamond.append(''.join(row))
        i -= 1
    return diamond