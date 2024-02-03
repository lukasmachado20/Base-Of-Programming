# Author: Lukas Silva Machado
# Algorithm: Selection Sort
# Logic: Ordenar o array selecionando o menor elemento da lista e colocar no inicio lista;
import random


def selection_sort(arr: list) -> list:
    """Order an array  elements.
    :param arr: array of elements
    :return: Return an ordered array
    """
    for i in range(len(arr)):
        min_element = arr[i]
        index_swap = i
        for j in range(i + 1, len(arr)):
            if arr[j] < min_element:
                min_element = arr[j]
                index_swap = j
        arr[i], arr[index_swap] = arr[index_swap], arr[i]
    return arr


def recursive_selection_sort(arr: list[int], size_array: int, index=0) -> list[int]:
    """Recursively order an array.
    :param arr: array of int elements
    :param size_array: size of array
    :param index: index of array
    :return: Return an ordered array.
    """
    if index > size_array - 1:
        return arr
    index_swap = index_min_element(arr, index, size_array - 1)
    if index_swap != index:
        arr[index], arr[index_swap] = arr[index_swap], arr[index]
    return recursive_selection_sort(arr, size_array, index + 1)


def index_min_element(arr: list, index: int, max_index: int):
    """This recursion iterate over array until the last index. When reach the last index of the list
        he goes recursively returning the index and checking with the penultimate element of the call.
    :param arr: array to order
    :param index: index of actual element
    :param max_index: last index of array
    :return: return index of minimum element of arr
    """
    if index == max_index:
        return index
    return_index = index_min_element(arr, index + 1, max_index)
    return index if arr[index] < arr[return_index] else return_index


def my_recursive_selection_sort(arr: list, size_array: int, index=0) -> list:
    """Recursive call without recursive checking function for minimum index.
    :param arr: array of elements
    :param size_array: size of array checked
    :param index: index of element
    :return: return an ordered array of number elements
    """
    if index > size_array - 1:
        return arr
    min_element = arr[index]
    index_swap = index
    for j in range(index + 1, size_array):
        if arr[j] < min_element:
            min_element = arr[j]
            index_swap = j
    arr[index], arr[index_swap] = arr[index_swap], arr[index]
    return recursive_selection_sort(arr, size_array, index + 1)


if __name__ == '__main__':
    array = random.sample(range(-1000, 1000), 500)
    array_for_recursive = array.copy()
    array_for_iterative = array.copy()

    # Printing arrays
    print(f"                   Not ordered array: {array}")
    print(f"Not ordered array for recursive call: {array_for_recursive}")

    # Ordering arrays
    recursive_ordered_array = my_recursive_selection_sort(array_for_recursive, len(array_for_recursive))
    iterative_ordered_array = selection_sort(array_for_iterative)
    python_ordered_array = list(sorted(array))

    # Print ordered arrays
    print(f"   Recursive Ordered array:{recursive_ordered_array}")
    print(f"      Python Ordered array:{python_ordered_array}")
    print(f"   Iterative Ordered array:{array_for_iterative}")

    # Checking my algorithms
    assert (python_ordered_array == recursive_ordered_array)
    assert (python_ordered_array == array_for_iterative)
