#include <stdio.h>

int main() {
    int n, i;
    
    // Ask user how many numbers they want to enter
    printf("Enter how many numbers you want: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input elements into the array
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sumOdd = 0, sumEven = 0;
    
    // Calculate sums based on position
    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {     // even position (2nd, 4th, ...)
            sumEven += arr[i];
        } else {                    // odd position (1st, 3rd, ...)
            sumOdd += arr[i];
        }
    }
    
    // Display results
    printf("\nSum of numbers at odd positions = %d", sumOdd);
    printf("\nSum of numbers at even positions = %d\n", sumEven);
    
    return 0;
}