#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime> 

using namespace std;
using namespace std::chrono;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

double measureTime(void (*sortFunc)(int[], int, int), int arr[], int left, int right) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, left, right);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

int main() {
    const int SIZE = 1000;

    srand(static_cast<unsigned int>(time(0)));

    int array_best[SIZE];
    int array_average[SIZE];
    int array_worst[SIZE];

    for (int i = 0; i < SIZE; i++) {
        array_best[i] = i + 1;
    }

    for (int i = 0; i < SIZE; i++) {
        array_average[i] = rand() % 10000;
    }

    for (int i = 0; i < SIZE; i++) {
        array_worst[i] = SIZE - i;
    }

    cout << "Merge Sort Times (in milliseconds):" << endl;
    cout << "  Best Case: " << measureTime(mergeSort, array_best, 0, SIZE - 1) << " ms" << endl;
    cout << "  Average Case: " << measureTime(mergeSort, array_average, 0, SIZE - 1) << " ms" << endl;
    cout << "  Worst Case: " << measureTime(mergeSort, array_worst, 0, SIZE - 1) << " ms" << endl;

    return 0;
}
