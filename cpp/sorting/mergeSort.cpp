#include <iostream>
#define size 5
using namespace std;
void merge(int A[], int l, int m, int r)
{
    int p = m - l + 1;
    int q = r - m;
    int L[p], R[q];
    for (int i = 0; i < p; i++)
    {
        L[i] = A[l + i];
    }
    for (int j = 0; j < q; j++)
    {
        R[j] = A[m + j];
    }
    // cout << "left array:" << endl;
    // for (int i = 0; i < p; i++)
    //     cout << L[i] << " ";
    // cout << endl;
    // cout << "right array:" << endl;
    // for (int j = 0; j < q; j++)
    //     cout << R[j] << " ";
}
int main()
{
    int A[size] = {5, 9, 1, 4, 8};
    int l = 0;
    int r = size - 1;
    int m = (l + r) / 2;
    merge(A, l, m, r);
    return 0;
}