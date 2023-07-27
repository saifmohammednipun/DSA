/*
 ** Keypoints**
 * Array should be sorted
 * Time Complexity: O(log(N))
 */

#include <iostream>
using namespace std;
#define SIZE 6
int main()
{
    int myArray[SIZE] = { 50, 12, 65, -5, 10, -8 };

    //Bubble Sort
    int temp = 0;
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE-i; j++)
        {
            if(myArray[j] > myArray[j+1])
            {
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }

    //Sorted Array
    for(int i=0; i<SIZE; i++)
    {
        cout<< myArray[i] <<" ";
    }
    
    cout <<endl;
    
    //Binary Search
    int v = 65;
    int low = 0;
    int high = SIZE-1;
    int flag = 0;
    int mid = 0;

    while(low <= high)
    {
        mid = low + (high-low)/2;
        
        if(myArray[mid] == v)
        {
            flag++; 
            break;
        }
        else if(myArray[mid] < v) low = mid + 1 ;
        else if(myArray[mid] > v) high = mid - 1;
        else break;
    }

    if(flag == 1) cout<< "Element Found at Index: " << mid <<endl;
    else cout<< "Element Not Found" <<endl;

  
    return 0;
}
