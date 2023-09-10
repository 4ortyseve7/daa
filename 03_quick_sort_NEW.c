QUICK SORT 

SUNIL SIR ALGORITHM IMPLEMENTATION

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int q) {
    int pivot = arr[q]; // Choose the last element as the pivot
    int i = p - 1;      // Initialize i as one less than p

    for (int j = p; j <= q - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place the pivot in its correct position
    swap(&arr[i + 1], &arr[q]);

    return i + 1; // Return the index of the pivot
}

void quickSort(int arr[], int p, int q) {
    if (p < q) {
        int pivotIndex = partition(arr, p, q);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, p, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, q);
    }
}

int main() {
    int arr[] = {12, 5, 9, 7, 2, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, size - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
