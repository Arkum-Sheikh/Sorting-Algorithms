#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, n);
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

    cout << "Selection Sort Times (in milliseconds):" << endl;
    cout << "  Best Case: " << measureTime(selectionSort, array_best, SIZE) << " ms" << endl;
    cout << "  Average Case: " << measureTime(selectionSort, array_average, SIZE) << " ms" << endl;
    cout << "  Worst Case: " << measureTime(selectionSort, array_worst, SIZE) << " ms" << endl;

    return 0;
}
