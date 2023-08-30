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

void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
   
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
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

    
     cout<< "Enter Your Choice";
     cin>>choice;
    
    
    switch(choice)
    {
        case 1: 
                generateRandomValues(dataSet1, SIZE1);

            
                cout<< "Data Set-1 Sorting Execution Times " <<endl;
                srand(time(NULL)); 

                startTime = time(NULL);
                bubbleSort(dataSet1);
                endTime = time(NULL);
                cout << "Bubble Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                 
                startTime = time(NULL);
                selectionSort(dataSet1);
                endTime = time(NULL);
                cout << "Selection Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
               
                startTime = time(NULL);
                insertionSort(dataSet1);
                endTime = time(NULL);
                cout << "Insertion Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                startTime = time(NULL);
                mergeSort(dataSet1,0,SIZE1);
                endTime = time(NULL);
                cout << "Merge Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
            break;

        case 2: 
                generateRandomValues(dataSet2, SIZE2);

                cout<< "Data Set-2 Sorting Execution Times " <<endl;
                srand(time(NULL)); 

                startTime = time(NULL);
                    bubbleSort(dataSet2);
                endTime = time(NULL);
                cout << "Bubble Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                 
                startTime = time(NULL);
                    selectionSort(dataSet2);
                endTime = time(NULL);
                cout << "Selection Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
               
                startTime = time(NULL);
                    insertionSort(dataSet2);
                endTime = time(NULL);
                cout << "Insertion Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
     
                startTime = time(NULL);
                    mergeSort(dataSet2,0,SIZE2);
                endTime = time(NULL);
                cout << "Merge Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                break;
                

        case 3: 
                generateRandomValues(dataSet3, SIZE3);

                cout<< "Data Set-3 Sorting Execution Times " <<endl;
                srand(time(NULL)); 

                startTime = time(NULL);
                    bubbleSort(dataSet3);
                endTime = time(NULL);
                cout << "Bubble Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                 
                startTime = time(NULL);
                    selectionSort(dataSet3);
                endTime = time(NULL);
                cout << "Selection Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
               
                startTime = time(NULL);
                    insertionSort(dataSet3);
                endTime = time(NULL);
                cout << "Insertion Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
     
                startTime = time(NULL);
                    mergeSort(dataSet3,0,SIZE3);
                endTime = time(NULL);
                cout << "Merge Sort Execution Time: " << endTime-startTime <<"s"<< endl;

                break;

        case 4: 
                generateRandomValues(dataSet4, SIZE4);

                cout<< "Data Set-4 Sorting Execution Times " <<endl;
                srand(time(NULL)); 

                startTime = time(NULL);
                    bubbleSort(dataSet4);
                endTime = time(NULL);
                cout << "Bubble Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                 
                startTime = time(NULL);
                    selectionSort(dataSet4);
                endTime = time(NULL);
                cout << "Selection Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
               
                startTime = time(NULL);
                    insertionSort(dataSet4);
                endTime = time(NULL);
                cout << "Insertion Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
     
                startTime = time(NULL);
                    mergeSort(dataSet4,0,SIZE4);
                endTime = time(NULL);
                cout << "Merge Sort Execution Time: " << endTime-startTime <<"s"<< endl;
   
                break;

        default:
                cout<< "Invalid Choice" <<endl;


    }


    return 0;
}