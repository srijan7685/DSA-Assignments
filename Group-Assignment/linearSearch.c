#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N;
    printf("Number of elements:\n> ");
    scanf("%d", &N);
    int random_numbers[N];

    // Generate N random integers
    srand(time(NULL));  // Seed the random number generator
    for (int i = 0; i < N; i++) {
        random_numbers[i] = rand() % 100 + 1;  // Generate a random integer between 1 and 100
    }

    // Generate a random target number within the range
    int target_number = rand() % 100 + 1;

    // Perform linear search
    clock_t start_time = clock();
    int index = linear_search(random_numbers, N, target_number);
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / (CLOCKS_PER_SEC / 1000);

    // Print the results
    printf("Random Numbers: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", random_numbers[i]);
    }
    printf("\nTarget Number: %d\n", target_number);

    if (index != -1) {
        printf("Target number found at index: %d\n", index);
    } else {
        printf("Target number not found.\n");
    }
    printf("Execution time: %.4f milliseconds\n", execution_time);

    return 0;
}
