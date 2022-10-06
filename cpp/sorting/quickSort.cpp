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
  cout << A[pivot] << endl;
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
int partitioningLast(int A[], int l, int h)
{
  int pivot = A[h];
  int i = (l - 1);
  for (int j = l; j < h; j++)
  {
    if (A[j] < pivot)
    {
      i++;
      swap(A[j], A[i]);
    }
  }
  swap(A[i + 1], pivot);
  return (i + 1);
}
void quickSort(int A[], int l, int h)
{
  // if (l < h)
  // {
  //   int index = partitioning(A, l, h);

  //   quickSort(A, l, index - 1);
  //   quickSort(A, index + 1, h);
  // }
}
int main()
{
  int A[8] = {300, 70, 60, 40, 80, 10, 20, 90};

  cout << endl;
  // quickSort(A, 0, 7);
  int index = partitioningLast(A, 0, 7);
  cout << "pivot index: " << index << endl;
  cout << "pivot element: " << A[index];
  // print sorted data
  // for (int i = 0; i < 8; i++)
  // {
  //   cout << A[i] << " ";
  // }
  return 0;
}
