#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int numDatasets = 4;
    const int datasetSizes[numDatasets] = {1000, 5000, 10000, 100000};

    for (int i = 0; i < numDatasets; ++i) {
        int dataSize = datasetSizes[i];
        int *dataset = new int[dataSize];

        for (int j = 0; j < dataSize; ++j) {
            dataset[j] = std::rand();
        }

        std::cout << "Dataset size: " << dataSize << std::endl;

        // Bubble Sort
        int *bubbleArr = new int[dataSize];
        std::copy(dataset, dataset + dataSize, bubbleArr);
        time_t start = std::time(nullptr);
        bubbleSort(bubbleArr, dataSize);
        time_t end = std::time(nullptr);
        std::cout << "Bubble Sort time: " << end - start << " seconds" << std::endl;

        // Selection Sort
        int *selectionArr = new int[dataSize];
        std::copy(dataset, dataset + dataSize, selectionArr);
        start = std::time(nullptr);
        selectionSort(selectionArr, dataSize);
        end = std::time(nullptr);
        std::cout << "Selection Sort time: " << end - start << " seconds" << std::endl;

        // Insertion Sort
        int *insertionArr = new int[dataSize];
        std::copy(dataset, dataset + dataSize, insertionArr);
        start = std::time(nullptr);
        insertionSort(insertionArr, dataSize);
        end = std::time(nullptr);
        std::cout << "Insertion Sort time: " << end - start << " seconds" << std::endl;

        // Merge Sort
        int *mergeArr = new int[dataSize];
        std::copy(dataset, dataset + dataSize, mergeArr);
        start = std::time(nullptr);
        mergeSort(mergeArr, 0, dataSize - 1);
        end = std::time(nullptr);
        std::cout << "Merge Sort time: " << end - start << " seconds" << std::endl;

        delete[] dataset;
        delete[] bubbleArr;
        delete[] selectionArr;
        delete[] insertionArr;
        delete[] mergeArr;
    }

    return 0;
}
