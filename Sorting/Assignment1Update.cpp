#include <bits/stdc++.h>
using namespace std;

#define SIZE1 100000
#define SIZE2 200000
#define SIZE3 300000
#define SIZE4 400000

void merge(int* arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)  L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)  M[j] = arr[q + 1 + j];


  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j]){
      arr[k] = L[i];
      i++;
    } else {
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

void insertionSort(int* dataSet, int size) {
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

void selectionSort(int* dataSet, int size) {
    for(int i=0; i<SIZE1-1; i++)
    {
        for(int j=i+1; j<SIZE1; j++)
        {
            if(dataSet[i]>dataSet[j]) swap(dataSet[i],dataSet[j]); 
        }
    }
}

void bubbleSort(int* dataSet, int size) {
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

void printDataSet(int* dataSet, int size) {
    for (int i = 0; i < size; i++) {
        cout << dataSet[i] << " ";
    }
    cout << endl;
}

void generateRandomValues(int* dataSet, int size) {
    int lowerBound = 0, upperBound = 100000;

    for (int i = 0; i < size; i++) {
        dataSet[i] = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    }
}

void measureSortTime(int* dataSet, int* dataSetCopy, int size, string sortName) {
    for (int i = 0; i < size; i++) {
        dataSetCopy[i] = dataSet[i]; // Create a copy to pass to sorting functions
    }

    time_t startTime, endTime;
    startTime = time(NULL);

    if (sortName == "Bubble")  bubbleSort(dataSetCopy, size);
    else if (sortName == "Selection") selectionSort(dataSetCopy, size);
    else if (sortName == "Insertion") insertionSort(dataSetCopy, size);
    else if (sortName == "Merge") mergeSort(dataSetCopy, 0, size - 1);
    
    endTime = time(NULL);
    cout << sortName << " Sort Execution Time for Dataset Size " << size << ": " << endTime - startTime << "s" << endl;
}

int main() {
    
    int choice;

    cout << "1. Data Set-1" << endl;
    cout << "2. Data Set-2" << endl;
    cout << "3. Data Set-3" << endl;
    cout << "4. Data Set-4" << endl;

    cout << "Enter Your Choice: ";
    cin >> choice;
    cout << endl;

    int* dataSet;
    int* dataSetCopy;
    int size;

    switch (choice) {
    case 1:
        dataSet = new int[SIZE1];
        dataSetCopy = new int[SIZE1];
        size = SIZE1;
        generateRandomValues(dataSet, size);

        cout << "Data Set-1 Sorting Execution Times " << endl;
        srand(time(NULL));

        measureSortTime(dataSet, dataSetCopy, size, "Bubble");
        measureSortTime(dataSet, dataSetCopy, size, "Selection");
        measureSortTime(dataSet, dataSetCopy, size, "Insertion");
        measureSortTime(dataSet, dataSetCopy, size, "Merge");

        delete[] dataSet;
        delete[] dataSetCopy;

        break;

    case 2:
        dataSet = new int[SIZE2];
        dataSetCopy = new int[SIZE2];
        size = SIZE2;
        generateRandomValues(dataSet, size);

        cout << "Data Set-2 Sorting Execution Times " << endl;
        srand(time(NULL));

        measureSortTime(dataSet, dataSetCopy, size, "Bubble");
        measureSortTime(dataSet, dataSetCopy, size, "Selection");
        measureSortTime(dataSet, dataSetCopy, size, "Insertion");
        measureSortTime(dataSet, dataSetCopy, size, "Merge");

        delete[] dataSet;
        delete[] dataSetCopy;

        break;

    case 3:
        dataSet = new int[SIZE3];
        dataSetCopy = new int[SIZE3];
        size = SIZE3;
        generateRandomValues(dataSet, size);

        cout << "Data Set-3 Sorting Execution Times " << endl;
        srand(time(nullptr));

        measureSortTime(dataSet, dataSetCopy, size, "Bubble");
        measureSortTime(dataSet, dataSetCopy, size, "Selection");
        measureSortTime(dataSet, dataSetCopy, size, "Insertion");
        measureSortTime(dataSet, dataSetCopy, size, "Merge");

        delete[] dataSet;
        delete[] dataSetCopy;

        break;

    case 4:
        dataSet = new int[SIZE4];
        dataSetCopy = new int[SIZE4];
        size = SIZE4;
        generateRandomValues(dataSet, size);

        cout << "Data Set-4 Sorting Execution Times " << endl;
        srand(time(NULL));

        measureSortTime(dataSet, dataSetCopy, size, "Bubble");
        measureSortTime(dataSet, dataSetCopy, size, "Selection");
        measureSortTime(dataSet, dataSetCopy, size, "Insertion");
        measureSortTime(dataSet, dataSetCopy, size, "Merge");

        delete[] dataSet;
        delete[] dataSetCopy;

        break;

    default:
        cout << "Invalid Choice" << endl;
    }

    return 0;
}
