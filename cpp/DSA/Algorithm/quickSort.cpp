#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partitioning(int A[], int l, int r)
{
    int lower = l;
    int upper = r;
    int pivot = l; // first element as pivot element
    // cout << A[pivot] << endl;
    while (lower < upper)
    {
        // increase form left most side until element is greater than pivot element
        while (A[lower] <= A[pivot])
        {
            lower++;
        }

        // decrease form right most side until element is less than pivot element
        while (A[upper] > A[pivot])
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(A[lower], A[upper]);
        }
    }
    swap(A[pivot], A[upper]);
    return upper;
}
// int partitioningLast(int A[], int l, int h)
// {
//     int pivot = A[h];
//     int i = (l - 1);
//     for (int j = l; j < h; j++)
//     {
//         if (A[j] < pivot)
//         {
//             i++;
//             swap(A[j], A[i]);
//         }
//     }
//     swap(A[i + 1], pivot);
//     return (i + 1);
// }
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int index = partitioning(A, l, h); // pivot index
        // recursive call on the left of pivot
        quickSort(A, l, index - 1);
        // recursive call on the right of pivot
        quickSort(A, index + 1, h);
    }
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{

    int A[] = {300, 70, 60, 40, 80, 10, 20, 90};
    int size = sizeof(A) / sizeof(A[0]);
    // performing quick sort in data
    quickSort(A, 0, size - 1);
    //  print sorted data
    printArray(A, size - 1);
    return 0;
}
