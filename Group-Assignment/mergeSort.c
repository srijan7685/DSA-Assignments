#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);
char lines[] = "--------------------------------------------------------------\n";

int main()
{
    printf("Implementation of Merge Sorting Algorithm\n");
    printf("%s", lines);
    int N; // Number of elements in the array
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
    printf("%s", lines);
    printf("Unsorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Measure the execution time using clock()
    clock_t start_time = clock();

    // Sort the array using merge sort
    merge_sort(array, N);

    // Measure the execution time
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("%s", lines);
    printf("Execution time: %.4f seconds\n", execution_time);
    printf("Space required: %lu bytes\n", N * sizeof(int));
    printf("-----------------------END------------------------------------");
    return 0;
}

void merge_sort(int a[], int length)
{
    merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
    // we stop recursion when l >= r
    if (l < r)
    {
        // find the midpoint of l and r
        int m = l + (r - l) / 2;
        // apply the function recursively to the left and right portions
        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);
        // merge the sorted portions of the array
        merge_sorted_arrays(a, l, m, r);
    }
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
    // calculate the length of the left and right portions of the array
    int left_length = m - l + 1;
    int right_length = r - m;
    // create temporary arrays to store these portions
    int temp_left[left_length];
    int temp_right[right_length];
    // used as index/counter variables for the 3 arrays a, temp_left, temp_right
    int i, j, k;
    // copy the left portion into the temp_left array
    for (int i = 0; i < left_length; i++)
        temp_left[i] = a[l + i];
    // copy the right portion into the temp_right array
    for (int i = 0; i < right_length; i++)
        temp_right[i] = a[m + 1 + i];
    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }
}
