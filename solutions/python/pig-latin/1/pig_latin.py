def translate_word(text: str) -> str:
    if text[0] in 'aeiou' or text.startswith(('xr', 'yt')):
        return f"{text}ay"
    if text.startswith('qu'):
        return f"{text[2:]}quay"

    i = 0
    if text[0] == 'y':
        i += 1
    while i < len(text):
        if text[i] in 'aeiouy':
            break
        if text[i] == 'q':
            i += 1
            if text[i] == 'u':
                i += 1
                break
        else:
            i += 1
    return f"{text[i:]}{text[:i]}ay"

def translate(text: str) -> str:
    strs = text.split(' ')
    i = 1
    pig = translate_word(strs[0])
    while i < len(strs):
        pig += ' '
        pig += translate_word(strs[i])
        i += 1
    return pig