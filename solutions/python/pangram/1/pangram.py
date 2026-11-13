def is_pangram(sentence):
    seen = [False] * 256
    length = 0
    for i in range(len(sentence)):
        if sentence[i].isalpha():
            if seen[ord(sentence[i].upper())] == False:
                seen[ord(sentence[i].upper())] = True
                length += 1
    if length >= 26:
        return True
    return False
