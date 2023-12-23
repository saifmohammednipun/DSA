#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[5] = {1,2,3,4,5};
    
    //Accessing array elements through pointers
    int* ptr = A;
    int* ptr1 = &A[0];

    //pointing -> Address of 1st index of the array
    cout<< ptr<<endl; 
    cout<< ptr1 <<endl;
    cout<< ptr+2 <<endl;

    //Dereferencing
    cout<< *(ptr) <<endl;
    cout<< *(ptr1) <<endl;
    cout<< *(ptr1+2) <<endl;

    return 0;
}