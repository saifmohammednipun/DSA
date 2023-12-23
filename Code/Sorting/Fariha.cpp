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
void customSortAlgorithm1(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void customSortAlgorithm2(int arr[], int size) {
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
void customSortAlgorithm3(int arr[], int size) {
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

void customSortAlgorithm4(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        customSortAlgorithm4(arr, left, middle);
        customSortAlgorithm4(arr, middle + 1, right);
        customMerge(arr, left, middle, right);
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Create datasets of different sizes
    int customSizes[] = {100000, 500000, 600000, 700000};
    
    for (int i = 0; i < 4; i++) {
        int size = customSizes[i];
        int customArr[size];
        
        // Initialize the array with random values
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customSortAlgorithm1
        time_t start, end;
        time(&start);
        customSortAlgorithm1(customArr, size); 
        time(&end);
        double customSortAlgorithm1Time = difftime(end, start);
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customSortAlgorithm2
        time(&start);
        customSortAlgorithm2(customArr, size);
        time(&end);
        double customSortAlgorithm2Time = difftime(end, start);
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customSortAlgorithm3
        time(&start);
        customSortAlgorithm3(customArr, size);
        time(&end);
        double customSortAlgorithm3Time = difftime(end, start);
        
        // Reset the array
        for (int j = 0; j < size; j++) {
            customArr[j] = rand();
        }
        
        // Measure the execution time for customSortAlgorithm4
        time(&start);
        customSortAlgorithm4(customArr, 0, size - 1);
        time(&end);
        double customSortAlgorithm4Time = difftime(end, start);
        
        // Print the execution times for each algorithm
        cout << "Dataset size: " << size << endl;
        cout << "customSortAlgorithm1 Time: " << customSortAlgorithm1Time << " seconds" << endl;
        cout << "customSortAlgorithm2 Time: " << customSortAlgorithm2Time << " seconds" << endl;
        cout << "customSortAlgorithm3 Time: " << customSortAlgorithm3Time << " seconds" << endl;
        cout << "customSortAlgorithm4 Time: " << customSortAlgorithm4Time << " seconds" << endl;
    }
    
    return 0;
}
