#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 20

// Function prototypes
int less(int i, int j);
void swap(int array[], int i, int j);
void basicSort(int array[]);
int isSorted(int array[]);
void insertionSort(int array[]);
void selectionSort(int array[]);
void merge(int array[], int l, int m, int r);
void mergesort(int array[], int l, int r);
void mergeBU(int array[], int l, int m, int r);
void mergesortBU(int array[], int arraySize);
void quicksort(int array[], int l, int r);
int partition(int array[], int l, int r);

// Helper functions
int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int Array[MAX_ELEMENTS] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("Original array: ");
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array[i]);
    }
    printf("\n\n");

    // Applying different sorting methods
    printf("Basic Sort:\n");
    basicSort(Array);
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array[i]);
    }
    printf("\nSorted: %d\n\n", isSorted(Array));

    int Array2[MAX_ELEMENTS] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("Insertion Sort:\n");
    insertionSort(Array2);
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array2[i]);
    }
    printf("\nSorted: %d\n\n", isSorted(Array2));

    int Array3[MAX_ELEMENTS] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("Selection Sort:\n");
    selectionSort(Array3);
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array3[i]);
    }
    printf("\nSorted: %d\n\n", isSorted(Array3));

    int Array4[MAX_ELEMENTS] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("Merge Sort:\n");
    mergesort(Array4, 0, MAX_ELEMENTS - 1);
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array4[i]);
    }
    printf("\nSorted: %d\n\n", isSorted(Array4));

    int Array5[MAX_ELEMENTS] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("Merge Sort (Bottom-Up):\n");
    mergesortBU(Array5, MAX_ELEMENTS);
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array5[i]);
    }
    printf("\nSorted: %d\n\n", isSorted(Array5));

    int Array6[MAX_ELEMENTS] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    printf("Quick Sort:\n");
    quicksort(Array6, 0, MAX_ELEMENTS - 1);
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        printf("%d ", Array6[i]);
    }
    printf("\nSorted: %d\n\n", isSorted(Array6));

    return 0;
}
