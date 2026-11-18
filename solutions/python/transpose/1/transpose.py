from itertools import zip_longest

def transpose(text):
    if not text:
        return ""
    lst = text.split('\n')
    padded = []
    max_len = 0
    for line in reversed(lst):
        max_len = max(max_len, len(line))
        padded.append(line.ljust(max_len))
    padded.reverse()
    lst = zip_longest(*padded, fillvalue="")
    lst = [''.join(col) for col in lst]
    return '\n'.join(lst)