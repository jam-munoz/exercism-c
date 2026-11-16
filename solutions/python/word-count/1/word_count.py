import re
import string

def count_words(sentence):
    D = {}
    sentence = re.sub(r"(?<!\w)'|'(?!\w)", "", sentence)
    punctuation = string.punctuation.replace("'", "")
    words = re.sub(f"[{re.escape(punctuation)}]", " ", sentence).casefold().split()
    for i in words:
        if D.setdefault(i, 0) != i:
            D[i] += 1
    return D
