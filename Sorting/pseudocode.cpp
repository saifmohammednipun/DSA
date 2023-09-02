// Include necessary headers
#include <bits/stdc++.h>

// Define the dataset sizes
#define SIZE1 100000
#define SIZE2 200000
#define SIZE3 300000
#define SIZE4 400000

// Function to merge two subarrays
void merge(int* arr, int p, int q, int r) {
    // Calculate sizes of two subarrays
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    // Copy data to temporary arrays L[] and M[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Merge the temporary arrays back into arr[p..r]
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of M[], if any
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to perform Insertion Sort
void insertionSort(int* dataSet, int size) {
    for (int i = 1; i < size; i++) {
        int current = dataSet[i];
        int j = i - 1;

        // Move elements of dataSet[0..i-1] that are greater than current
        // to one position ahead of their current position
        while (j >= 0 && dataSet[j] > current) {
            dataSet[j + 1] = dataSet[j];
            j--;
        }

        // Place current at the correct position
        dataSet[j + 1] = current;
    }
}

// Function to perform Selection Sort
void selectionSort(int* dataSet, int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in unsorted part of dataSet
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (dataSet[j] < dataSet[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(dataSet[i], dataSet[minIndex]);
    }
}

// Function to perform Bubble Sort
void bubbleSort(int* dataSet, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (dataSet[j] > dataSet[j + 1]) {
                swap(dataSet[j], dataSet[j + 1]);
            }
        }
    }
}

// Function to print the dataset
void printDataSet(int* dataSet, int size) {
    for (int i = 0; i < size; i++) {
        cout << dataSet[i] << " ";
    }
    cout << endl;
}

// Function to generate random values for the dataset
void generateRandomValues(int* dataSet, int size) {
    int lowerBound = 0, upperBound = 100000;
    for (int i = 0; i < size; i++) {
        dataSet[i] = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    }
}

// Function to check if an array is sorted
bool isSorted(int* dataSet, int size) {
    for (int i = 1; i < size; i++) {
        if (dataSet[i] < dataSet[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to measure the execution time of a sorting algorithm
void measureSortTime(int* dataSet, int* dataSetCopy, int size, string sortName) {
    // Create a copy of the dataset to pass to sorting functions
    for (int i = 0; i < size; i++) {
        dataSetCopy[i] = dataSet[i];
    }

    // Measure the start time
    time_t startTime, endTime;
    startTime = time(NULL);

    // Perform the sorting based on the provided sortName
    if (sortName == "Bubble") bubbleSort(dataSetCopy, size);
    else if (sortName == "Selection") selectionSort(dataSetCopy, size);
    else if (sortName == "Insertion") insertionSort(dataSetCopy, size);
    else if (sortName == "Merge") mergeSort(dataSetCopy, 0, size - 1);

    // Measure the end time
    endTime = time(NULL);

    // Print the execution time
    cout << sortName << " Sort Execution Time for Dataset Size " << size << ": " << endTime - startTime << "s" << endl;

    // Check if the dataset is sorted and print a warning if not
    if (!isSorted(dataSetCopy, size)) {
        cout << "Warning: The " << sortName << " Sort did not produce a sorted dataset." << endl;
    }
}

// Main function
int main() {
    int choice;

    // Display menu for dataset selection
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

    // Seed the random number generator once at the beginning
    srand(time(NULL));

    switch (choice) {
        case 1:
            // Initialize dataset and datasetCopy for Data Set-1
            dataSet = new int[SIZE1];
            dataSetCopy = new int[SIZE1];
            size = SIZE1;

            // Generate random values for the dataset
            generateRandomValues(dataSet, size);

            // Display the dataset size
            cout << "Data Set-1 Sorting Execution Times " << endl;

            // Measure and display execution times for each sorting algorithm
            measureSortTime(dataSet, dataSetCopy, size, "Bubble");
            measureSortTime(dataSet, dataSetCopy, size, "Selection");
            measureSortTime(dataSet, dataSetCopy, size, "Insertion");
            measureSortTime(dataSet, dataSetCopy, size, "Merge");

            // Deallocate memory
            delete[] dataSet;
            delete[] dataSetCopy;
            break;

        // Similar cases for Data Set-2, Data Set-3, and Data Set-4

        default:
            cout << "Invalid Choice" << endl;
    }

    return 0;
}
