def equilateral(sides: list[int]) -> bool:
    if sides[0] <= 0 or sides[1] <= 0 or sides[2] <= 0 or sides[0] + sides[1] < sides[2] or sides[1] + sides[2] < sides[0] or sides[0] + sides[2] < sides[1]:
        return False
    return sides[0] == sides[1] and sides[1] == sides[2]


def isosceles(sides: list[int]) -> bool:
    if sides[0] <= 0 or sides[1] <= 0 or sides[2] <= 0 or sides[0] + sides[1] < sides[2] or sides[1] + sides[2] < sides[0] or sides[0] + sides[2] < sides[1]:
        return False
    return sides[0] == sides[1] or sides[1] == sides[2] or sides[0] == sides[2]


def scalene(sides: list[int]) -> bool:
    if sides[0] <= 0 or sides[1] <= 0 or sides[2] <= 0 or sides[0] + sides[1] < sides[2] or sides[1] + sides[2] < sides[0] or sides[0] + sides[2] < sides[1]:
        return False
    return not(sides[0] == sides[1] or sides[1] == sides[2] or sides[0] == sides[2])
