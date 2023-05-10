#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

int heapify(vector<int>& arr, int n, int i, int& comparisons) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[i] < arr[l]) {
        largest = l;
        comparisons++;
    }

    if (r < n && arr[largest] < arr[r]) {
        largest = r;
        comparisons++;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons++;
        comparisons = heapify(arr, n, largest, comparisons);
    }

    return comparisons;
}

vector<int> heap_sort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        comparisons = heapify(arr, n, i, comparisons);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        comparisons++;
        comparisons = heapify(arr, i, 0, comparisons);
    }

    return arr;
}

int main() {
    srand(time(nullptr));

    for (int size = 30; size <= 1000; size += 10) {
        vector<int> inputs(size);
        for (int i = 0; i < size; i++) {
            inputs[i] = rand() % 1000;
        }

        auto start_time = high_resolution_clock::now();
        vector<int> sorted_arr = heap_sort(inputs);
        auto end_time = high_resolution_clock::now();

        int comparisons = 0;
        heap_sort(inputs);
        cout << "Input size: " << size << ", Comparisons: " << comparisons << ", Time: " << duration_cast<microseconds>(end_time - start_time).count() << " microseconds" << endl;
    }

    return 0;
}
