#include <iostream>
#include <ctime>
#include <cstdlib>

#define SIZE1 100000
#define SIZE2 500000
#define SIZE3 600000
#define SIZE4 700000


using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void customBubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void customSelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void customInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void customMerge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    int leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void customMergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        customMergeSort(arr, left, middle);
        customMergeSort(arr, middle + 1, right);
        customMerge(arr, left, middle, right);
    }
}

int main() {      
    srand(time(NULL));  // Seed the random number generator
    
    for (int i = 0; i < 4; i++) {    
        int size;

        if(i==0) size=SIZE1;
        else if(i==1) size = SIZE2;
        else if(i==2) size = SIZE3;
        else if(i==3) size = SIZE4;

        int customArr[size];
        
        // Initialize the array with random values
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customBubbleSort
        time_t start, end;
        start = time(NULL);
        customBubbleSort(customArr, size); 
        end = time(NULL);
        int BubbleSortTime = end - start;
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customSelectionSort
        start = time(NULL);
        customSelectionSort(customArr, size);
        end = time(NULL);
        int SelectionSortTime = end - start;
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customInsertionSort
        start = time(NULL);
        customInsertionSort(customArr, size);
        end = time(NULL);
        int InsertionSortTime = end - start;;
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customMergeSort
        start = time(NULL);
        customMergeSort(customArr, 0, size - 1);
        end = time(NULL);
        int MergeSortTime = end - start;
        
        // Print the execution times for each algorithm
        cout << "Dataset size: " << size << endl;
        cout << "BubbleSort Time: " << BubbleSortTime << " seconds" << endl;
        cout << "SelectionSort Time: " << SelectionSortTime << " seconds" << endl;
        cout << "nsertionSort Time: " << InsertionSortTime << " seconds" << endl;
        cout << "MergeSort Time: " << MergeSortTime<< " seconds" << endl;
    }
    
    return 0;
}
