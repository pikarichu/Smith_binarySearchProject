#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;


int recursiveBinarySearch(const std::vector<int>& arr, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            return recursiveBinarySearch(arr, target, mid + 1, high);
        }
        else {
            return recursiveBinarySearch(arr, target, low, mid - 1);

        }
    }
    else {
        return -1; // Target not found
    }
}

int iterativeBinarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
            // Target found
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1; // Target not found  

}

int sequentialSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Target found at index i
        }
    }

    return -1; // Target not found
}

int main() {
    
    int N = 200000;
    double sumRBS = 0;
    double sumIBS = 0;
    double sumSeqS = 0;
    int target;
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    int result;

    vector<int> arr = { };
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> distribution(1, 100);
    for (int i = 0; i < 10; ++i)
    {
        arr = { };
        for (int j = 0; j < N; ++j) 
        {
            int random_number = distribution(rng);
            arr.insert(arr.begin(), random_number);
        }
        sort(arr.begin(), arr.end());
        target = distribution(rng);
        start_time = chrono::high_resolution_clock::now();
        result = recursiveBinarySearch(arr, target, 0, arr.size() - 1);

        if (result != -1) {
            std::cout << target << " Element found at index: " << result << std::endl;

        }
        else {
            std::cout << target << "Element not found in the array." << std::endl;

        }
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        sumRBS += duration;
        cout << "Execution Time: " << duration << " microseconds" << endl;
        cout << endl;

        start_time = chrono::high_resolution_clock::now();
        result = iterativeBinarySearch(arr, target);

        if (result != -1) {
            std::cout << target << " Element found at index: " << result << std::endl;
        }
        else {
            std::cout << target << "Element not found in the array." << std::endl;
        }
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        sumIBS += duration;
        cout << "Execution Time: " << duration << " microseconds" << endl;
        cout << endl;


        start_time = chrono::high_resolution_clock::now();
        result = sequentialSearch(arr, target);

        if (result != -1) {
            std::cout << target << " Element found at index: " << result << std::endl;
        }
        else {
            std::cout << target << "Element not found in the array." << std::endl;
        }
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        sumSeqS += duration;
        cout << "Execution Time: " << duration << " microseconds" << endl;

        cout << endl;



    }
    cout << "Sum RBS: " << sumRBS << endl;
    cout << "Sum IBS: " << sumIBS << endl;
    cout << "Sum SeqS: " << sumSeqS << endl;
    cout << "Average Running Time for Recursive Binary Search in microseconds is " << sumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << sumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Seach in microseconds is " << sumSeqS / 10 << endl;

    return 0;
}