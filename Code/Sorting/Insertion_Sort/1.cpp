#include <iostream>
using namespace std;

#define SIZE 5

int main()
{
    int arr[SIZE] = {12, 11, 13, 5, 6};

    for (int i = 1; i < SIZE; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }

    for (int k = 0; k < SIZE; k++)
    {
        cout << arr[k] << " ";
    }
    return 0;
}
