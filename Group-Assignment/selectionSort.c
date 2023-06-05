#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int array[], int length);
int* getUniqueRandomNumbers(int N);

int main()
{
    printf("Execution of Selection Sort Algorithm...\n");
    int N; // Define the number of elements in the array
    printf("Specify the size of the array: ");
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        printf("Input is invalid. Please enter a positive integer.\n");
        return 1; // Terminate the program with an error code
    }

    int* array = getUniqueRandomNumbers(N);
    if (array == NULL)
    {
        printf("Error: Unable to allocate memory for the array.\n");
        return 1; // Exit the program with an error code
    }

    printf("Array before sorting:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Start measuring the execution time using clock()
    clock_t start_time = clock();

    // Apply selection sort algorithm to sort the array
    selection_sort(array, N);

    // Start measuring the execution time
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / (CLOCKS_PER_SEC / 1000);

    // Display the sorted array
    printf("Array after sorting:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Actual Time taken for execution: %.4f milliseconds\n", execution_time);
    printf("Space required: %lu bytes\n", N * sizeof(int));

    free(array);
    return 0;
}

void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int* getUniqueRandomNumbers(int N)
{
    int* array = (int*)malloc(N * sizeof(int));
    if (array == NULL)
    {
        return NULL; // Memory allocation failed.
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        int randomNum = rand() % N + 1;

        // Identify and check for duplicates within the generated array
        for (int j = 0; j < i; j++)
        {
            if (array[j] == randomNum)
            {
                // Found a duplicate, generating a new random number.
                randomNum = rand() % N + 1;
                // Restarting the loop to recheck from the beginning.
                j = -1;
            }
        }

        array[i] = randomNum;
    }

    return array;
}
