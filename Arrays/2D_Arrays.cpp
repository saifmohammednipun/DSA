#include <bits/stdc++.h>
using namespace std;
int main()
{

    int A[3][3] = { 1,2,3,
                    4,5,6,
                    7,8,9 };

    int B[3] = {1,2,3};

    //Using a single pointer variable
    int* ptr = A[0];
    int* ptr1 = &A[0][0];

    cout<< *(ptr) <<endl;
    cout<< *(ptr1) <<endl;

    //Address of [i][j]th Element. Formula: (p+i*n+j)  ex. A[1][2] 
    cout<< *(ptr1 + 1*3 +2) << endl;

    //Using a concept of Array Pointer Variable
    cout<< (*(*(ptr1 + 1) + 2)) <<endl;

    int (*p)[3][3] = &A;
    int (*p1)[3] = &B;
    cout<< p1 <<endl;

    
    return 0;
}