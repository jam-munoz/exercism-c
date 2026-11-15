def find(search_list, value):
    if not search_list or value > search_list[-1]:
        raise ValueError("value not in array")
    left = 0
    right = len(search_list)
    while left <= right:
        mid = (left + right) // 2
        if value == search_list[mid]:
            return mid
        elif value < search_list[mid]:
            right = mid - 1
        else:
            left = mid + 1
    raise ValueError("value not in array")
