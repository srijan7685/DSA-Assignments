#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to heapify a subtree rooted at 'root' in the array
void heapify(int arr[], int n, int root) {
    int largest = root; // Initialize the largest element as the root
    int left = 2 * root + 1; // Left child index
    int right = 2 * root + 2; // Right child index

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != root) {
        // Swap the root with the largest element
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build the initial max heap from the array
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (i = n - 1; i >= 0; i--) {
        // Move the current root (maximum element) to the end1
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Re-heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int N;
    printf("Enter the size of array:\n>> ");
    scanf("%d", &N);

    int* array = (int*)malloc(N * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Generate N random integer
    for (int i = 0; i < N; i++)
    {
        array[i] = i + 1; // Fill the array with numbers from 1 to N at first
    }

    for (int i = N - 1; i > 0; i--)
    {
        // Generate a random index between 0 and i
        int j = rand() % (i + 1);
        // Swap the elements at index i and j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    printf("Unsorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Sort the array using merge sort
    heapSort(array, N);

    // Measure the execution time
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;
    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Execution time: %.4f milliseconds\n", execution_time);
    printf("Space required: %lu bytes\n", N * sizeof(int));
    printf("-----------------------END------------------------------------");
    return 0;
}


