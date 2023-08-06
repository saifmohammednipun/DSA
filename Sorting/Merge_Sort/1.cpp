#include <bits/stdc++.h>
using namespace std;
#define SIZE 8


int arr[SIZE];

void merge(int l, int r, int mid)
{
    int left_size = mid-1+1;
    int l[left_size + 1]; 

    int right_size = r - (mid+1) - 1;
    int r[right_size + 1];

    for(int i=l, j=0; i<=mid; i++, j++)
    {
        l[j] = arr[i];
    }

    for(int i=mid+1,j=0; i<=r; i++, j++)
    {
        r[j] = arr[i];

    }

    l[left_size] = INT_MAX;
    r[right_size] = INT_MAX;

}


void mergeSort(int l, int r)
{
    if(l == r) return;
    int mid = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,r,mid);
}
void printArray(int* arr)
{
    for(int i=0; i<SIZE; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    arr[SIZE] = {12, 7, 3, 9, 2, 5, 4, 18};
    mergeSort(0,SIZE-1);
    printArray(arr);
   
    return 0;
}