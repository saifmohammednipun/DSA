/*
 ** Keypoints**
 * Comparing adjacent values
 * Larger value will always pushed to the right
 * Time Complexity: O(N^2)
 */

#include <iostream>
using namespace std;
#define SIZE 6

int main()
{
    int myArray[SIZE] = { 50, 12, 65, -5, 10, -8 };
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

    //asending order
    for(int i=0; i<SIZE; i++)
    {
        cout<< myArray[i] << " ";
    }

    cout <<endl;

    //desending order
    for(int i=SIZE-1; i>=0; i--)
    {
        cout<< myArray[i] << " ";
    }
    
    return 0;
}