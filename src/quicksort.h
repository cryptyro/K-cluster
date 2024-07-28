#include <time.h>

// Function to swap two elements
void swap(struct Edge* a, struct Edge* b) {
    struct Edge temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using a random pivot element
int partition(struct Edge *arr, int low, int high) {
    // Generate a random index between low and high
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    // Swap the pivot element with the last element
    swap(&arr[random], &arr[high]);

    struct Edge pivot = arr[high]; // Pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j].weight <= pivot.weight) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement randomized quicksort
void quickSort(struct Edge *arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
