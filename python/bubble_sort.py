# Author: Lukas Silva Machado
# Algorithm: Selection Sort
# Logic: Ordenar a lista percorrendo cada elemento e flutuando o maior elemento para o topo da lista;
import random


def bubble_sort(arr: list) -> list:
    size_arr = len(arr) - 1
    for pass_index in range(size_arr, 0, -1):
        for i in range(pass_index):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        print("ITERATIVE NOT SHORT!!!")
    return arr


def short_bubble_sort(arr: list) -> list:
    swapped = True
    passed_index = len(arr) - 1
    while passed_index > 0 and swapped:
        swapped = False
        for i in range(passed_index):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
        passed_index -= 1
        print("ITERATIVE SHORT!!!")
    return arr


def recursive_bubble_sort(arr, total_indexes):
    if total_indexes <= 0:
        return arr
    for i in range(total_indexes):
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
    print("REC NOT SHORT!!!!")
    return recursive_bubble_sort(arr, total_indexes - 1)


def recursive_short_bubble_sort(arr, size_array, swapped=True):
    if size_array <= 0 or not swapped:
        return arr
    for i in range(size_array - 1):
        swapped = False
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
            swapped = True
    print("REC SHORT!!!!")
    return recursive_short_bubble_sort(arr, size_array - 1, swapped)


if __name__ == '__main__':
    array = [1, 2, 3, 4]  # list(random.sample(range(-100, 100), 5))
    array_for_recursive_bbs = array.copy()
    array_for_iterative_bbs = array.copy()
    array_for_iterative_short_bbs = array.copy()
    array_for_recursive_short_bbs = array.copy()

    # Printing arrays
    print(f"                    Not ordered array: {array}")
    print(f"Not ordered array for recursive call : {array_for_recursive_bbs}")
    print(f"Not ordered array for iterative short: {array_for_recursive_bbs}")
    print(f"Not ordered array for iterative short: {array_for_recursive_bbs}")
    print(f"Not ordered array for recursive short: {array_for_recursive_short_bbs}")

    iterative_ordered_bbs = bubble_sort(
        array_for_iterative_bbs
    )
    recursive_ordered_bbs = recursive_bubble_sort(
        array_for_recursive_bbs,
        len(array_for_recursive_bbs) - 1
    )
    iterative_ordered_short_bbs = short_bubble_sort(
        array_for_iterative_short_bbs
    )
    recursive_ordered_short_bbs = recursive_short_bubble_sort(
        array_for_recursive_short_bbs,
        len(array_for_iterative_short_bbs)
    )
    python_ordered_array_bbs = list(
        sorted(array)
    )

    # Print ordered arrays
    print(f"            Python Ordered array:{python_ordered_array_bbs}")
    print(f"         Iterative Ordered array:{iterative_ordered_bbs}")
    print(f"         Recursive Ordered array:{recursive_ordered_bbs}")
    print(f"   Short Recursive Ordered array:{recursive_ordered_bbs}")

    assert (python_ordered_array_bbs == iterative_ordered_bbs)
    assert (python_ordered_array_bbs == recursive_ordered_bbs)
    assert (python_ordered_array_bbs == iterative_ordered_short_bbs)
    assert (python_ordered_array_bbs == recursive_ordered_short_bbs)
