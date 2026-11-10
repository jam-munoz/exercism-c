def convert(n: int) -> str:
    if n % 105 == 0:
        return "PlingPlangPlong"
    elif n % 35 == 0:
        return "PlangPlong"
    elif n % 21 == 0:
        return "PlingPlong"
    elif n % 15 == 0:
        return "PlingPlang"
    elif n % 7 == 0:
        return "Plong"
    elif n % 5 == 0:
        return "Plang"
    elif n % 3 == 0:
        return "Pling"
    return str(n)
