#include <bits/stdc++.h>
using namespace std;

#define SIZE1 100000
#define SIZE2 200000
#define SIZE3 300000
#define SIZE4 400000

int *dataSet1 = new int[SIZE1];
int *dataSet2 = new int[SIZE2];
int *dataSet3 = new int[SIZE3];
int *dataSet4 = new int[SIZE4];


int *dataSetCopy1 = new int[SIZE1];
int *dataSetCopy2 = new int[SIZE2];
int *dataSetCopy3 = new int[SIZE3];
int *dataSetCopy4 = new int[SIZE4];



void merge(int* arr, int p, int q, int r)
 {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];


  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  
  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    } 
    else 
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void insertionSort(int* dataSet)
{
    for (int i = 1; i < SIZE1; i++)
    {
        int current = dataSet[i];
        int j = i - 1;

        while (j >= 0 && dataSet[j] > current)
        {
            dataSet[j+1] = dataSet[j];
            j--;
        }

        dataSet[j+1] = current;
    }

}

void selectionSort(int* dataSet)
{
    for(int i=0; i<SIZE1-1; i++)
    {
        for(int j=i+1; j<SIZE1; j++)
        {
            if(dataSet[i]>dataSet[j]) 
                swap(dataSet[i],dataSet[j]); 
        }
    }
}


void bubbleSort(int* dataSet)
{
int temp=0;

for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE1-i; j++)
        {
            if(dataSet[j] > dataSet[j+1])
            {
                temp = dataSet[j];
                dataSet[j] = dataSet[j+1];
                dataSet[j+1] = temp;
            }
        }
    }
}


void printDataSet(int* dataSet, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << dataSet[i] << " ";
    }
}

void generateRandomValues(int* dataSet,int size)
{
    int lowerBound = 0, upperBound = 100000;
    
    for(int i=0; i<size; i++)
    {
        dataSet[i] = (rand() % (upperBound-lowerBound+1)) + lowerBound;
    }
}


int main()
{
    int choice;
    time_t startTime, endTime;

    cout<<  "1. Data Set-1" <<endl;
    cout<<  "2. Data Set-2" <<endl;
    cout<<  "3. Data Set-3" <<endl;
    cout<<  "4. Data Set-4"  <<endl;

     cout << "Enter Your Choice: ";
     cin >> choice;
     cout << endl;
    
    switch (choice)
    {

     case 1:
        generateRandomValues(dataSet1, SIZE1);

        cout << "Data Set-1 Sorting Execution Times " << endl;
        srand(time(NULL));

        // Create a copy of the unsorted dataset to pass to sorting functions
        for (int i = 0; i < SIZE1; i++)
        {
            dataSetCopy1[i] = dataSet1[i];
        }

        startTime = time(NULL);
        bubbleSort(dataSetCopy1);
        endTime = time(NULL);
        cout << "Bubble Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE1; i++)
        {
            dataSetCopy1[i] = dataSet1[i];
        }

        startTime = time(NULL);
        selectionSort(dataSetCopy1);
        endTime = time(NULL);
        cout << "Selection Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE1; i++)
        {
            dataSetCopy1[i] = dataSet1[i];
        }

        startTime = time(NULL);
        insertionSort(dataSetCopy1);
        endTime = time(NULL);
        cout << "Insertion Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE1; i++)
        {
            dataSetCopy1[i] = dataSet1[i];
        }

        startTime = time(NULL);
        mergeSort(dataSetCopy1, 0, SIZE1 - 1);
        endTime = time(NULL);
        cout << "Merge Sort Execution Time: " << endTime - startTime << "s" << endl;

        printDataSet(dataSetCopy1,SIZE1);

        delete[] dataSetCopy1;
        delete[] dataSet1;
        
        break;

    case 2:
        generateRandomValues(dataSet2, SIZE2);

        cout << "Data Set-2 Sorting Execution Times " << endl;
        srand(time(NULL));

        // Store copy of the unsorted dataset to pass to sorting functions
        for (int i = 0; i < SIZE2; i++)
        {
            dataSetCopy2[i] = dataSet2[i];
        }

        startTime = time(NULL);
        bubbleSort(dataSetCopy2);
        endTime = time(NULL);
        cout << "Bubble Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy array
        for (int i = 0; i < SIZE2; i++)
        {
            dataSetCopy2[i] = dataSet2[i];
        }

        startTime = time(NULL);
        selectionSort(dataSetCopy2);
        endTime = time(NULL);
        cout << "Selection Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy array 
        for (int i = 0; i < SIZE2; i++)
        {
            dataSetCopy2[i] = dataSet2[i];
        }

        startTime = time(NULL);
        insertionSort(dataSetCopy2);
        endTime = time(NULL);
        cout << "Insertion Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy array 
        for (int i = 0; i < SIZE2; i++)
        {
            dataSetCopy2[i] = dataSet2[i];
        }

        startTime = time(NULL);
        mergeSort(dataSetCopy2, 0, SIZE2 - 1);
        endTime = time(NULL);
        cout << "Merge Sort Execution Time: " << endTime - startTime << "s" << endl;

        delete[] dataSetCopy2;
        delete[] dataSet2;


        break;

case 3:
        generateRandomValues(dataSet3, SIZE3);

        cout << "Data Set-3 Sorting Execution Times " << endl;
        srand(time(NULL));

        // Create a copy of the unsorted dataset to pass to sorting functions
        for (int i = 0; i < SIZE3; i++)
        {
            dataSetCopy3[i] = dataSet3[i];
        }

        startTime = time(NULL);
        bubbleSort(dataSetCopy3);
        endTime = time(NULL);
        cout << "Bubble Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE3; i++)
        {
            dataSetCopy3[i] = dataSet3[i];
        }

        startTime = time(NULL);
        selectionSort(dataSetCopy3);
        endTime = time(NULL);
        cout << "Selection Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE3; i++)
        {
            dataSetCopy3[i] = dataSet3[i];
        }

        startTime = time(NULL);
        insertionSort(dataSetCopy3);
        endTime = time(NULL);
        cout << "Insertion Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE3; i++)
        {
            dataSetCopy3[i] = dataSet3[i];
        }

        startTime = time(NULL);
        mergeSort(dataSetCopy3, 0, SIZE3 - 1);
        endTime = time(NULL);
        cout << "Merge Sort Execution Time: " << endTime - startTime << "s" << endl;
        
        delete[] dataSetCopy3;
        delete[] dataSet3;
        

        break;
 
case 4:
        generateRandomValues(dataSet4, SIZE4);

        cout << "Data Set-4 Sorting Execution Times " << endl;
        srand(time(NULL));

        // Store a copy of the unsorted dataset to pass to sorting functions

        for (int i = 0; i < SIZE4; i++)
        {
            dataSetCopy4[i] = dataSet4[i];
        }

        startTime = time(NULL);
        bubbleSort(dataSetCopy4);
        endTime = time(NULL);
        cout << "Bubble Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE4; i++)
        {
            dataSetCopy4[i] = dataSet4[i];
        }

        startTime = time(NULL);
        selectionSort(dataSetCopy4);
        endTime = time(NULL);
        cout << "Selection Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE4; i++)
        {
            dataSetCopy4[i] = dataSet4[i];
        }

        startTime = time(NULL);
        insertionSort(dataSetCopy4);
        endTime = time(NULL);
        cout << "Insertion Sort Execution Time: " << endTime - startTime << "s" << endl;

        // Reset the copy
        for (int i = 0; i < SIZE4; i++)
        {
            dataSetCopy4[i] = dataSet4[i];
        }

        startTime = time(NULL);
        mergeSort(dataSetCopy4, 0, SIZE4 - 1);
        endTime = time(NULL);
        cout << "Merge Sort Execution Time: " << endTime - startTime << "s" << endl;

        delete[] dataSet4;
        delete[] dataSetCopy4;
    
        break;
    
    default:
        cout << "Invalid Choice" << endl;
    }

    return 0;
}
