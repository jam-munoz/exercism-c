import math 

def score(x, y):
    h = math.hypot(x, y)
    if h <= 1: 
        return 10
    elif h <= 5:
        return 5
    elif h <= 10:
        return 1
    return 0