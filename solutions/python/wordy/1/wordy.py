def answer(question):
    if not question.startswith("What is "):
        raise ValueError("syntax error")
    lst = question[8:].rstrip("?")
    lst = lst.split()
    if not lst[0].lstrip('+-').isdigit():
        raise ValueError("syntax error")
    res = int(lst[0])
    i = 1
    length = len(lst)
    while i < length:
        match lst[i]:
            case "plus":
                i += 1
                if i >= length or not lst[i].lstrip('+-').isdigit():
                    raise ValueError("syntax error")
                res += int(lst[i])
            case "minus":
                i += 1
                if i >= length or not lst[i].lstrip('+-').isdigit():
                    raise ValueError("syntax error")
                res -= int(lst[i])
            case "multiplied": 
                i += 2
                if i >= length or not lst[i].lstrip('+-').isdigit():
                    raise ValueError("syntax error")
                res *= int(lst[i])
            case "divided": 
                i += 2
                if i >= length or not lst[i].lstrip('+-').isdigit():
                    raise ValueError("syntax error")
                res //= int(lst[i])
            case _ if lst[i].isalpha():
                raise ValueError("unknown operation")
            case _: 
                raise ValueError("syntax error")
        i += 1
    return res