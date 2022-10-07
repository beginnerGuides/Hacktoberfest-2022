#include <iostream>
using namespace std;

// Merge sort
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k++] = arr[i++];
        }
        else
        {
            c[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        c[k++] = arr[i++];
    }
    while (j <= high)
    {
        c[k++] = arr[j++];
    }
    // Adding elements into original array.
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        // divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        // merge or conquer sorted arrays
        merge(arr, low, high, mid);
    }
}

// read input array and call mergesort
int main()
{
    int num;
    cout << "Enter number of elements to be sorted:";
    cin >> num;
    int myarray[num];
    cout << "Enter " << num << " elements to be sorted:";
    for (int i = 0; i < num; i++)
    {
        cin >> myarray[i];
    }
    merge_sort(myarray, 0, num - 1);
    cout << "Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout << myarray[i] << "\t";
    }
}