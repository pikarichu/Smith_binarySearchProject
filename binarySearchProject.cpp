#include <iostream>
#include <vector>
#include <random>

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
    //int high = arr.size() - 1;
    int high = 10;
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
    
    vector<int> arr = { };
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> distribution(1, 100);
    //arr.begin();
    for (int i = 0; i < 10; ++i) {
    
        int random_number = distribution(rng);
        arr.insert(arr.begin(), random_number);
    }
    //std::vector<int> arr = { 6, 5, 7, 8, 1, 3, 4, 2, 9, 10 };
    sort(arr.begin(), arr.end());

    int target = 6;
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    int result = recursiveBinarySearch(arr, target, 0, arr.size() - 1);

    if (result != -1) {
        std::cout << target << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << target << "Element not found in the array." << std::endl;

    }
    
    /*for (int i = 0; i < 100; ++i)
    {
        int result = recursiveBinarySearch(arr, i, 0, arr.size() - 1);

        if (result != -1) {
            std::cout << i << ": Element found at index: " << result << std::endl;
        }
        else {
            std::cout << i << ": Element not found in the array." << std::endl;

        }
    }*/

    result = iterativeBinarySearch(arr, target);

    if (result != -1) {
        std::cout << target << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << target << "Element not found in the array." << std::endl;
    }

    result = sequentialSearch(arr, target);

    if (result != -1) {
        std::cout << target << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << target << "Element not found in the array." << std::endl;
    }

    return 0;
}