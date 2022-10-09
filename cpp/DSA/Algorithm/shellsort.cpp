#include<iostream>
#include<iomanip>
using namespace std;
void shellSort(int a[], int n) 
{
int t,i,j,gap;
    for ( gap = n / 2; gap >=1; gap /= 2)
        {   
           for (j = gap; j < n; j++) 
               {     
                   for (i=j-gap;i>=0; i=i-gap)
                        {     
                            if(a[i+gap]>a[i])
                                break;
                           else
                                { t=a[i+gap];
                                  a[i+gap]=a[i];
                                  a[i]=t;
                                }
                          }
                                    
                  }
            }
}
void printArray(int array[], int size)
 {  
       int i;
      for (i = 0; i < size; i++)    
         cout << array[i] << " ";  cout << endl;
 }
int main()
  {
         int data[20],size,i;
         cout<<"\n Enter Total numbers in the array :";
          cin>>size;
       for(i=0;i<size;i++)
        {  cout<<"\n Enter array Element :";
        cin>>data[i];
       }
     cout<<"\n Original Array :";
     printArray(data, size);
         
         shellSort(data, size);
         cout << "\nSorted array: \n";
         printArray(data, size);
}

