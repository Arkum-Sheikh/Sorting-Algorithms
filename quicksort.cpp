#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double measureTime(void (*sortFunc)(int[], int, int), int arr[], int low, int high) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, low, high);
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

    cout << "Quick Sort Times (in milliseconds):" << endl;
    cout << "  Best Case: " << measureTime(quickSort, array_best, 0, SIZE - 1) << " ms" << endl;
    cout << "  Average Case: " << measureTime(quickSort, array_average, 0, SIZE - 1) << " ms" << endl;
    cout << "  Worst Case: " << measureTime(quickSort, array_worst, 0, SIZE - 1) << " ms" << endl;

    return 0;
}
