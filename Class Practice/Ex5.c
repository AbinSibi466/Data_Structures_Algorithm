#include <stdio.h>
#include <stdlib.h>

// Define Employee structure
struct Employee {
    int id;
    char name[50];
    // Add other relevant fields
};

// Function to perform linear search
int linear_search(struct Employee arr[], int n, int target, int *comparisons) {
    for (int i = 0; i < n; ++i) {
        (*comparisons)++;
        if (arr[i].id == target) {
            return i;
        }
    }
    return -1;
}

// Function to perform sentinel search
int sentinel_search(struct Employee arr[], int n, int target, int *comparisons) {
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
int binary_search(struct Employee arr[], int n, int target, int *comparisons) {
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
void bubble_sort(struct Employee arr[], int n, int *element_comparisons, int *data_transfers) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            (*element_comparisons)++;
            if (arr[j].id > arr[j + 1].id) {
                // Swap the elements
                struct Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                (*data_transfers)++;
            }
        }
    }
}

// Function to perform insertion sort
void insertion_sort(struct Employee arr[], int n, int *element_comparisons, int *data_transfers) {
    for (int i = 1; i < n; ++i) {
        struct Employee key = arr[i];
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
    const int n = 5; // Number of employees

    struct Employee employees[n] = {
        {101, "John"},
        {103, "Alice"},
        {102, "Bob"},
        {105, "Eve"},
        {104, "Charlie"}
    };

    int target_id = 103;

    // Linear Search
    int linear_index, linear_comparisons = 0;
    linear_index = linear_search(employees, n, target_id, &linear_comparisons);
    printf("Linear Search: Employee found at index %d with %d element comparisons\n", linear_index, linear_comparisons);

    // Bubble Sort
    int bubble_element_comparisons = 0, bubble_data_transfers = 0;
    bubble_sort(employees, n, &bubble_element_comparisons, &bubble_data_transfers);
    printf("Bubble Sort: %d element comparisons, %d data transfers\n", bubble_element_comparisons, bubble_data_transfers);

    // Binary Search
    int binary_index, binary_comparisons = 0;
    binary_index = binary_search(employees, n, target_id, &binary_comparisons);
    printf("Binary Search: Employee found at index %d with %d element comparisons\n", binary_index, binary_comparisons);

    // Sentinel Search
    int sentinel_index, sentinel_comparisons = 0;
    sentinel_index = sentinel_search(employees, n, target_id, &sentinel_comparisons);
    printf("Sentinel Search: Employee found at index %d with %d element comparisons\n", sentinel_index, sentinel_comparisons);

    // Insertion Sort
    int insertion_element_comparisons = 0, insertion_data_transfers = 0;
    insertion_sort(employees, n, &insertion_element_comparisons, &insertion_data_transfers);
    printf("Insertion Sort: %d element comparisons, %d data transfers\n", insertion_element_comparisons, insertion_data_transfers);

    return 0;
}
