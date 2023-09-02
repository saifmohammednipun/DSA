#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
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
void insertionSort(int arr[], int size) {
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
void merge(int arr[], int left, int middle, int right) {
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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        
        merge(arr, left, middle, right);
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Create datasets of different sizes
    int sizes[] = {1000, 5000, 10000, 100000};
    
    for (int i = 0; i < 4; i++) {
        int size = sizes[i];
        int arr[size];
        
        // Initialize the array with random values
        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }
        
        // Measure the execution time for Bubble Sort
        time_t start, end;
        time(&start);
        bubbleSort(arr, size);
        time(&end);
        double bubbleSortTime = difftime(end, start);
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }
        
        // Measure the execution time for Selection Sort
        time(&start);
        selectionSort(arr, size);
        time(&end);
        double selectionSortTime = difftime(end, start);
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }
        
        // Measure the execution time for Insertion Sort
        time(&start);
        insertionSort(arr, size);
        time(&end);
        double insertionSortTime = difftime(end, start);
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }
        
        // Measure the execution time for Merge Sort
        time(&start);
        mergeSort(arr, 0, size - 1);
        time(&end);
        double mergeSortTime = difftime(end, start);
        
        // Print the execution times for each algorithm
        cout << "Dataset size: " << size << endl;
        cout << "Bubble Sort Time: " << bubbleSortTime << " seconds" << endl;
        cout << "Selection Sort Time: " << selectionSortTime << " seconds" << endl;
        cout << "Insertion Sort Time: " << insertionSortTime << " seconds" << endl;
        cout << "Merge Sort Time: " << mergeSortTime << " seconds" << endl;
    }
    
    return 0;
}
