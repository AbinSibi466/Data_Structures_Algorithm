#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a movie
struct Movie {
    char title[100];
    char genre[50];
    int releaseYear;
    double rating;
};

// Variables to count comparisons for each sorting technique
int mergeSortComparisons = 0;
int quickSortComparisons = 0;

// Function to print a movie
void printMovie(struct Movie *movie) {
    printf("Title: %s, Genre: %s, Release Year: %d, Rating: %.2f\n", movie->title, movie->genre, movie->releaseYear, movie->rating);
}

// Function to perform Merge Sort on an array of movies
void merge(struct Movie arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct Movie L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        mergeSortComparisons++;  // Increment the comparison count for Merge Sort
        if (L[i].releaseYear <= R[j].releaseYear) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort on an array of movies
void mergeSort(struct Movie arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to partition the array for Quick Sort
int partition(struct Movie arr[], int low, int high) {
    struct Movie pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        quickSortComparisons++;  // Increment the comparison count for Quick Sort
        if (arr[j].releaseYear <= pivot.releaseYear) {
            i++;

            // Swap arr[i] and arr[j]
            struct Movie temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    struct Movie temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Function to perform Quick Sort on an array of movies
void quickSort(struct Movie arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursive sort the elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to read movies from a file
void readMoviesFromFile(char *filename, struct Movie arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fscanf(file, "%[^,],%[^,],%d,%lf\n", arr[*size].title, arr[*size].genre, &arr[*size].releaseYear, &arr[*size].rating) != EOF) {
        (*size)++;
    }

    fclose(file);
}

// Function to write movies to a file
void writeMoviesToFile(char *filename, struct Movie arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s,%s,%d,%.2f\n", arr[i].title, arr[i].genre, arr[i].releaseYear, arr[i].rating);
    }

    fclose(file);
}

int main() {
    struct Movie moviesMerge[100];
    struct Movie moviesQuick[100];
    int sizeMerge, sizeQuick;

    // Read movies from a file for Merge Sort
    readMoviesFromFile("movies.txt", moviesMerge, &sizeMerge);

    // Perform Merge Sort
    mergeSort(moviesMerge, 0, sizeMerge - 1);

    printf("Movies after Merge Sort:\n");
    for (int i = 0; i < sizeMerge; i++) {
        printMovie(&moviesMerge[i]);
    }

    // Write sorted movies to a file for Merge Sort
    writeMoviesToFile("sorted_movies_merge.txt", moviesMerge, sizeMerge);

    // Read movies from the file again for Quick Sort
    readMoviesFromFile("movies.txt", moviesQuick, &sizeQuick);

    // Perform Quick Sort
    quickSort(moviesQuick, 0, sizeQuick - 1);

    printf("\nMovies after Quick Sort:\n");
    for (int i = 0; i < sizeQuick; i++) {
        printMovie(&moviesQuick[i]);
    }

    // Write sorted movies to a file for Quick Sort
    writeMoviesToFile("sorted_movies_quick.txt", moviesQuick, sizeQuick);

    // Display comparison results
    printf("\nComparison Results:\n");
    printf("Merge Sort Comparisons: %d\n", mergeSortComparisons);
    printf("Quick Sort Comparisons: %d\n", quickSortComparisons);

    return 0;
}
