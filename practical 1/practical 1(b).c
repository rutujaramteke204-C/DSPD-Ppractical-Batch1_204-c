#include <stdio.h>

// Binary Search function
int binarySearch(int arr[], int size, int key) {
    // Check for invalid or empty input
    if (arr == NULL || size == 0) {
        return -1;   // NULL equivalent in C (no value found)
    }

    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;  // Find middle index

        // Print the value at the middle
        printf("Checking middle value: %d (Index %d)\n", arr[mid], mid);

        // If middle value matches the key
        if (arr[mid] == key) {
            printf("Value found at index %d!\n", mid);
            return mid;
        }
        // If key is greater, search in the right half
        else if (key > arr[mid]) {
            printf("Searching right side from index %d\n", mid + 1);
            start = mid + 1;
        }
        // If key is smaller, search in the left half
        else {
            printf("Searching left side till index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    // If not found
    printf("Value not found in the list.\n");
    return -1;
}

int main() {
    int n, key;

    // Take input from user
    printf("Enter number of elements : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Search list is empty.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d sorted numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    // Call binary search function
    binarySearch(arr, n, key);

    return 0;
}