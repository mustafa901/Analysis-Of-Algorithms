#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>  
#include <ctime>   

using namespace std;

void insertion_sort(int arr[], int n) {
    int sorted_size = 1;
    while (sorted_size < n) {
        int next_item = arr[sorted_size];
        int i = sorted_size - 1;
        while (i >= 0 && next_item < arr[i]) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = next_item;
        sorted_size++;
    }
}

bool array_equals(int arr1[], int n1, int arr2[], int n2) {
    if (n1 != n2) return false;
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

bool test(void (*sort_func)(int*, int)) {
    bool pass = true;

    int test1[5] = {1, 4, 2, 3, 5};
    int test1_ans[5] = {1, 2, 3, 4, 5};
    sort_func(test1, 5);
    if (!array_equals(test1, 5, test1_ans, 5)) {
        cout << "Test 1 failed" << endl;
        pass = false;
    }



    if (pass) {
        cout << "All tests passed!" << endl;
    }
    return pass;
}

void timing_experiment(void (*sort_func)(int*, int), const char* filename) {
    ofstream file;
    file.open(filename);
    file << "Array Size,Average Time (microseconds)\n";

    for (int size = 0; size <= 1000; size += 10) {
        long long total_time = 0;
        for (int trial = 0; trial < 1000; trial++) {
            int* arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;  
            }

            auto start = chrono::high_resolution_clock::now();
            sort_func(arr, size);
            auto end = chrono::high_resolution_clock::now();

            total_time += chrono::duration_cast<chrono::microseconds>(end - start).count();
            delete[] arr;
        }

        double avg_time = static_cast<double>(total_time) / 1000.0;
        file << size << "," << avg_time << "\n";
    }
    file.close();
}

int main() {
    srand(static_cast<unsigned>(time(0))); 

    if (test(insertion_sort)) {
        cout << "Insertion Sort: All tests passed." << endl;
    } else {
        cout << "Insertion Sort: Some tests failed." << endl;
    }

    timing_experiment(insertion_sort, "insertion_sort_times.csv");

    return 0;
}
