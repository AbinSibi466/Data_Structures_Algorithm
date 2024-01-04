#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Photograph structure
struct Photograph {
    int id;
    char title[100];
    int resolution; // Added field for photography
    // Add other relevant fields for photography
};

// Function to perform linear search
int linear_search(struct Photograph arr[], int n, int target, int *comparisons) {
    for (int i = 0; i < n; ++i) {
        (*comparisons)++;
        if (arr[i].id == target) {
            return i;
        }
    }
    return -1;
}

// Function to perform sentinel search
int sentinel_search(struct Photograph arr[], int n, int target, int *comparisons) {
    int last_id = arr[n - 1].id;
    arr[n - 1].id = target;

    int i = 0;
    while (arr[i].id != target) {
        (*comparisons)++;
        i++;
    }

    arr[n - 1].id = last_id;

    if (i < n - 1 || arr[n - 1].id == target) {
        return i;
    } else {
        return -1;
    }
}

// Function to perform binary search
int binary_search(struct Photograph arr[], int n, int target, int *comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        (*comparisons)++;
        int mid = (low + high) / 2;

        if (arr[mid].id == target) {
            return mid;
        } else if (arr[mid].id < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Function to perform bubble sort
void bubble_sort(struct Photograph arr[], int n, int *element_comparisons, int *data_transfers) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            (*element_comparisons)++;
            if (arr[j].id > arr[j + 1].id) {
                // Swap the elements
                struct Photograph temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                (*data_transfers)++;
            }
        }
    }
}

// Function to perform insertion sort
void insertion_sort(struct Photograph arr[], int n, int *element_comparisons, int *data_transfers) {
    for (int i = 1; i < n; ++i) {
        struct Photograph key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].id > key.id) {
            (*element_comparisons)++;
            // Move elements greater than key to one position ahead
            arr[j + 1] = arr[j];

            (*data_transfers)++;
            j--;
        }

        arr[j + 1] = key;
        (*data_transfers)++;
    }
}

int main() {
    const int n = 5; // Number of photographs

    struct Photograph photographs[n] = {
        {201, "Landscape", 24},      // Added resolution field
        {203, "Portrait", 20},
        {202, "Macro", 36},
        {205, "Cityscape", 30},
        {204, "Black and White", 18}
    };

    int target_id = 203;

    // Linear Search
    int linear_index, linear_comparisons = 0;
    linear_index = linear_search(photographs, n, target_id, &linear_comparisons);
    printf("Linear Search: Photograph found at index %d with %d element comparisons\n", linear_index, linear_comparisons);

    // Bubble Sort
    int bubble_element_comparisons = 0, bubble_data_transfers = 0;
    bubble_sort(photographs, n, &bubble_element_comparisons, &bubble_data_transfers);
    printf("Bubble Sort: %d element comparisons, %d data transfers\n", bubble_element_comparisons, bubble_data_transfers);

    // Binary Search
    int binary_index, binary_comparisons = 0;
    binary_index = binary_search(photographs, n, target_id, &binary_comparisons);
    printf("Binary Search: Photograph found at index %d with %d element comparisons\n", binary_index, binary_comparisons);

    // Sentinel Search
    int sentinel_index, sentinel_comparisons = 0;
    sentinel_index = sentinel_search(photographs, n, target_id, &sentinel_comparisons);
    printf("Sentinel Search: Photograph found at index %d with %d element comparisons\n", sentinel_index, sentinel_comparisons);

    // Insertion Sort
    int insertion_element_comparisons = 0, insertion_data_transfers = 0;
    insertion_sort(photographs, n, &insertion_element_comparisons, &insertion_data_transfers);
    printf("Insertion Sort: %d element comparisons, %d data transfers\n", insertion_element_comparisons, insertion_data_transfers);

    return 0;
}
