#include <iostream>
using namespace std;

#define SIZE 4
int main()
{
    int arr[SIZE] ={20,40,10,30};


    //Asending Order
    for(int i=0; i<SIZE-1; i++)
    {
        for(int j=i+1; j<SIZE; j++)
        {
            if(arr[i]>arr[j]) swap(arr[i],arr[j]); 
        }
    }

    //Desending Order
    // for(int i=0; i<SIZE-1; i++)
    // {
    //     for(int j=i+1; j<SIZE; j++)
    //     {
    //         if(arr[i]<arr[j]) swap(arr[i],arr[j]); 
    //     }
    // }

    for(int i=0; i<SIZE; i++)
    {
        cout << arr[i] << " ";
    }



    return 0;
}