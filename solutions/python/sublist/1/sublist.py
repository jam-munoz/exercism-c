"""
This exercise stub and the test suite contain several enumerated constants.

Enumerated constants can be done with a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = 1
SUPERLIST = 2
EQUAL = 3
UNEQUAL = 4

def sublist(list_one, list_two):
    if list_one == list_two:
        return EQUAL
    elif not list_two:
        return SUPERLIST
    elif not list_one:
        return SUBLIST
    i = j = k = 0
    while i < len(list_one):
        if list_one[i] == list_two[j]:
            while i + k < len(list_one) and list_one[i + k] == list_two[j]:
                k += 1
                j += 1
                if j == len(list_two):
                    return SUPERLIST
            i += 1
            j = 0
            k = 0
        else:
            i += 1
    i = j = k = 0
    while i < len(list_two):
        if list_two[i] == list_one[j]:
            while i + k < len(list_two) and list_two[i + k] == list_one[j]:
                k += 1
                j += 1
                if j == len(list_one):
                    return SUBLIST
            i += 1
            j = 0
            k = 0
        else:
            i += 1
    return UNEQUAL
