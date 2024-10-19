#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>  
#include <ctime>  

using namespace std;

void merge_sort(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]){
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

    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge_sort(arr, left, mid, right);
}

void merge_sort(int arr[], int n) {
    merge_sort(arr, 0, n - 1);
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

    if (test(merge_sort)) {
        cout << "Merge Sort: All tests passed." << endl;
    } else {
        cout << "Merge Sort: Some tests failed." << endl;
    }

    timing_experiment(merge_sort, "merge_sort_times.csv");

    return 0;
}