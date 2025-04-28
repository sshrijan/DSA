#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    // Outer loop - one by one move the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Assume the current index is the minimum
        minIdx = i;

        // Inner loop - find the index of the minimum element in the remaining unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size n

    // Input elements from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the selectionSort function to sort the array
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
