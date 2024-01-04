#include <stdio.h>

// Function to perform binary search and count occurrences
int countOccurrences(int arr[], int n, int target) {
    int firstIndex = -1;  // To store the first occurrence index
    int lastIndex = -1;   // To store the last occurrence index

    // Binary search to find the first occurrence
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            firstIndex = mid;
            high = mid - 1;  // Continue searching in the left half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Reset low and high for the next binary search
    low = 0;
    high = n - 1;

    // Binary search to find the last occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            lastIndex = mid;
            low = mid + 1;  // Continue searching in the right half
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Calculate the count of occurrences
    int count = (firstIndex != -1 && lastIndex != -1) ? (lastIndex - firstIndex + 1) : 0;

    return count;
}

// Example usage
int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int occurrences = countOccurrences(arr, n, target);

    if (occurrences > 0) {
        printf("The number %d occurs %d times in the array.\n", target, occurrences);
    } else {
        printf("The number %d does not exist in the array.\n", target);
    }

    return 0;
}  