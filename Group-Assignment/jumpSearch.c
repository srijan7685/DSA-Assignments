#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>


// Function to perform jump search
char lines[] = "************************************************************\n";
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[(int)fmin(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < target) {
        prev++;
        if (prev == fmin(step, n))
            return -1;
    }

    if (arr[prev] == target)
        return prev;

    return -1;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generateRandomNumbers(int arr[], int n) { // Function to generate random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

// Function to print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    printf("%s", lines);
    printf("####### Implementation of Jump search Algorithm #######\n");
    printf("%s", lines);
    int n; // Number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Array to store the random numbers
    generateRandomNumbers(arr, n);

    printf("Original array: ");
    printArray(arr, n);

    // Perform sorting operation
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    int target; // Element to search for
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform searching operation
    clock_t start = clock();
    int index = jumpSearch(arr, n, target);
    clock_t end = clock();
    double timeTaken = ((double) (start)) / CLOCKS_PER_SEC / 1000;
    for (int i = 0; i < n; i++)

        if (index != -1) {
            printf("Element found at index %d.\n", index);
        } else {
            printf("Element not found 1.\n");
        }
    printf("\n");
    printf("Time taken: %.4f ms.\n", timeTaken);
    printf("Space required: %lu bytes.\n", n * sizeof(int));
    printf("********************END**************************");
    return 0;
}