#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("###############################################\n");
    printf("####### Implementation of Jump Search #########\n");
    printf("###############################################\n");

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    generateRandomNumbers(arr, n);

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int index = jumpSearch(arr, n, target);

    clock_gettime(CLOCK_MONOTONIC, &end);
    double timeTaken = (end.tv_sec - start.tv_sec) * 1000.0 +
                       (end.tv_nsec - start.tv_nsec) / 1000000.0;

    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    printf("\n");
    printf("Time taken: %.4f milliseconds.\n", timeTaken);
    printf("Space required: %lu bytes.\n", n * sizeof(int));
    printf("###############################################\n");

    return 0;
}
