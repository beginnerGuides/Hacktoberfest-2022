#include <bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binSearch(arr, l, mid - 1, x);
 
        return binSearch(arr, mid + 1, r, x);
    }
 

    return -1;
}
 
int main()
{
    int arr[] = { -20, 30, 45, 150, 240 };
    int x = 150;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binSearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}