# C-Sorting-Algorithms
C-Sorting-Algorithms provides essential sorting algorithms implemented in C. This repository includes popular techniques like Bubble, Insertion, Selection, Merge, and Quick Sort. Each algorithm is modular and well-documented, allowing easy integration into projects. The `main.c` file demonstrates their functionality by sorting an array of integers.

## Files

### `sorting.c`

This file contains the implementations of the following sorting algorithms:

- **Basic Sort (Bubble Sort)**: This algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
  
- **Insertion Sort**: It builds the sorted array one item at a time by repeatedly removing the next element from the input data and inserting it into the correct position in the already sorted part of the array.
  
- **Selection Sort**: This algorithm sorts an array by repeatedly finding the minimum element from the unsorted part and putting it at the beginning.
  
- **Merge Sort**: Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, sorts each half separately, and then merges the sorted halves.
  
- **Merge Sort (Bottom-Up)**: This variation of Merge Sort avoids recursion by iteratively merging sub-arrays of increasing size.
  
- **Quick Sort**: Quick Sort is another divide-and-conquer algorithm that picks an element as a pivot and partitions the array around the pivot.

Each sorting algorithm is implemented as a separate function within the file.

### `main.c`

This file serves as the main program to demonstrate the functionality of the sorting algorithms implemented in `sorting.c`. It contains a `main` function that creates an array of integers, applies each sorting algorithm to the array, and prints the sorted array along with a message indicating whether it is sorted correctly.

## Usage

To use these sorting algorithms in your own projects, follow these steps:

1. Include the `sorting.c` file in your project.
2. Include the function prototypes of the sorting algorithms you wish to use in your code.
3. Call the desired sorting function with the array you want to sort as its argument.

For example, to use the Merge Sort algorithm in your code:

```c
#include "sorting.c"

int main() {
    int array[] = {5, 2, 9, 1, 7};
    int size = sizeof(array) / sizeof(array[0]);

    mergesort(array, 0, size - 1);

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
