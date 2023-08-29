def binary_search(list, item) -> (int, None) :
    low = 0
    high = len(list) - 1

    while low <= high:
        mid = (low + high) // 2
        number = list[mid]
        if number == item:
            return mid
        if number > item:
            high = mid - 1
        else:
            low = mid + 1
    return None


my_list = [5, 10, 31, 66, 88, 111, 666, 777]

print(binary_search(my_list, 4))