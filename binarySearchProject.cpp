#include <iostream>
#include <vector>

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
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int target = 6;

    int result = recursiveBinarySearch(arr, target, 0, arr.size() - 1);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;

    }

    result = iterativeBinarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;
    }

    result = sequentialSearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}