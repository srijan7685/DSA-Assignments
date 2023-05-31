#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main()
{
    // test array and length
    int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    // sort the array using merge sort
    merge_sort(array, length);

    // print out the array elements to verify they have been sorted
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");

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
