#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, array is sorted
        if (!swapped)
            break;
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Variable-length array (C99 or later)

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
