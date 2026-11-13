def is_isogram(phrase):
    seen = [False] * 256
    for i in range(len(phrase)):
        if phrase[i].isalpha():
            if seen[ord(phrase[i].upper())] == True:
                return False
            else:
                seen[ord(phrase[i].upper())] = True
    return True