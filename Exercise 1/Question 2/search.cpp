/**
 * @file search.cpp
 * @brief Implementation of Linear Search and Binary Search algorithms.
 * 
 * @author Abdullah Sheriff
 * @date Februrary 8th, 2025
 */

#include <iostream>
#include "sort.h"

using std::cin;
using std::cout;
using std::endl;

using std::numeric_limits; using std::streamsize; // For handling input exceptions
using std::bad_alloc;

// ====== Utilities ======
bool isInvalidInput();
int isSorted(const int [], const int, const bool);

// ====== Array Utilities ======
int getArraySizeInput();
int* getArrayInput(const int);
int* deepCopyArray(const int[], const int);

// ====== Input Utilities ======
int getIntegerInput();

// ====== Printing Utilities ======
void printArray(const int[], const int);

// ====== Searching Functions ======
int binarySearch(const int, const int [], const int);
int linearSearch(const int, const int [], const int);


int main() {
    int size, value, idx;
    unsigned int user_choice;
    int* arr; int* arr_copy;

    size = getArraySizeInput();
    arr = getArrayInput(size);
    cout << endl;
    
    do {
        arr_copy = deepCopyArray(arr, size);

        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Exit" << endl;
        cout << endl;

        do {
            cout << "Enter your choice (1-3): ";
            cin >> user_choice;

            if (isInvalidInput() || user_choice < 1 || user_choice > 3) {
                cout << "Invalid input. Please enter an integer between (1-3)." << endl;
            }
            else {
                break;
            }
        } while (true);
        cout << endl;

        switch(user_choice) {
            case 1:
                value = getIntegerInput();
                idx = linearSearch(value, arr, size);

                if (idx >= 0) {
                    cout << value << " found at index " << idx << endl;
                }
                else if (idx == -1) {
                    cout << value << " not found." << endl;
                } 
                else if (idx == -2) {
                    cout << "Error: Invalid input. The array is either null or size is a non-positive integer." << endl;
                } 
                cout << endl;
                break;

            case 2:
                printArray(arr_copy, size);
                cout << "Sorting the array. Binary search requires a sorted array." << endl;
                selectionSort(arr_copy, size);
                printArray(arr_copy, size);
                cout << endl;

                value = getIntegerInput();
                idx = binarySearch(value, arr_copy, size);

                if (idx >= 0) {
                    cout << value << " found at index " << idx << endl;
                }
                else if (idx == -1) {
                    cout << value << " not found." << endl;
                }
                else if (idx == -2) {
                    cout << "Error: Invalid input. The array is either null or size is a non-positive integer." << endl;
                }
                else if (idx == -3) {
                    cout << "Error: Invalid input. The array is not sorted in ascending order." << endl;
                }
                cout << endl;
                break;
            case 3:
                return 0;
                break;
        }
    } while (true);

    return 0;
}

/**
 * @brief Checks whether the previous input was invalid.
 * 
 * @return True, if the input is invalid; otherwise, false.
 * 
 * @code
 * int num;
 * std::cin >> num;
 * 
 * if (isInvalidInput()) {
 *      std::cout << "Invalid input. Please enter a valid integer." << std::endl;
 * }
 * @endcode
 */
bool isInvalidInput() {
    if (cin.fail()) {
        // Handle datatype mismatch
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    } else if (cin.peek() != '\n') {
        // Handle extra inputs
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Checks whether the array is sorted or not.
 * 
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * @param desc If true, checks whether the array is sorted in descending order; otherwise, ascending order.
 * 
 * @return Index of the maximum element in the array.
 * @return -2, if @p arr is null or if @p size is a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * int sorted_arr[] = {1, 2, 3, 4, 5};
 * 
 * isSorted(arr, 5); // Returns 0
 * isSorted(sorted_arr, 5); // Returns 1
 * isSorted(sorted_arr, 5, true); // Returns 0
 * @endcode
 */
int isSorted(const int arr[], const int size, const bool desc=false) {
    if (arr == NULL) {
        return -2;
    }
    if (size <= 0) {
        return -2;
    }

    for (int i = 1; i < size; i++) {
        if (desc ? arr[i] > arr[i-1] : arr[i] < arr[i-1]) return 0;
    }

    return 1;
}

/**
 * @brief Returns a value for size of an array and validates input.
 * 
 * @code
 * int size = getArraySizeInput();
 * 
 * // Output: "Enter a positive array size: 5" 
 * // Returns 5
 * @endcode
 */
int getArraySizeInput() {
    int size;

    do {
        cout << "Enter a positive array size: ";
        cin >> size;

        if (isInvalidInput() || size < 1) {
            cout << "Invalid input. Please enter a valid integer greater than (0)." << endl;
        }
        else {
            return size;
        }
    } while (true);
}

/**
 * @brief Returns an array and validates its elements.
 * 
 * @param size Number of elements in the array.
 * 
 * @note @p size must be a non-negative integer.
 * 
 * @code
 * int size = 5;
 * int* arr = getArrayInput(size);
 * 
 * // Output: "Enter 5 integers separated by spaces: 5 4 3 2 1" 
 * // Returns {5, 4, 3, 2, 1}
 * @endcode
 */
int* getArrayInput(const int size) {
    if (size <= 0) {
        return nullptr;
    }

    int* arr;

    try {
        arr = new int[size];
    } catch (const bad_alloc& e) {
        return nullptr;
    }

    do {
        cout << "Enter " << size << " integers separated by spaces: ";

        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        if (isInvalidInput()) {
            cout << "Invalid input. Enter only " << size << " integers separated by spaces." << endl;
        }
        else {
            return arr;
        }
    } while (true);
}

/**
 * @brief Returns a copy of an array. 
 * 
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * 
 * @return Pointer to a copy of the array.
 * 
 * @note @p arr must be a non-null pointer, and @p size must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * int arr_copy = deepCopyArray(arr, 5); // arr_copy = {5, 1, 2, 3, 4}
 * @endcode
 */
int* deepCopyArray(const int arr[], const int size) {
    if (!arr) {
        return nullptr;
    }
    if (size <= 0) {
        return nullptr;
    }

    int* arr_copy;

    try {
        arr_copy = new int[size];
    } catch (const bad_alloc& e) {
        return nullptr;
    }

    for (int i = 0; i < size; i++) {
        arr_copy[i] = arr[i];
    }

    return arr_copy;
}

/**
 * @brief Prompts the user for integer input and validates it.
 * 
 * @return Integer entered by the user.
 * 
 * @code
 * int value = getIntegerInput();
 * std::cout << "You entered: " << value << std::endl;
 * @endcode
 */
int getIntegerInput() {
    int value;

    do {
        cout << "Enter an integer: ";
        cin >> value;

        if (isInvalidInput()) {
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else {
            return value;
        }
    } while (true);
}

/**
 * @brief Prints the elements in an array.
 * 
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * 
 * @note @p arr must be a non-null pointer, and @p size must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * printArray(arr, 5) // Output: "Array elements: 5 1 2 3 4"
 * @endcode
 */
void printArray(const int arr[], const int size) {
    if (!arr) {
        return;
    }
    if (size < 0) {
        return;
    }
    if (size == 0) {
        cout << "Array is empty." << endl;
    }

    cout << "Array elements: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

/**
 * @brief Returns the index of the first occurrence of an element in the array using linear search algorithm.
 * 
 * @param value Number to be searched in the array.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * 
 * @return Index of @p value in the array, if found; otherwise, -1.
 * @return -2, if @p arr is null or if @p size is a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * 
 * linearSearch(3, arr, 5); // Returns 3
 * linearSearch(6, arr, 5); // Returns -1
 * @endcode
 */
int linearSearch(const int value, const int arr[], const int size) {
    if (arr == NULL) {
        return -2;
    }
    if (size <= 0) {
        return -2;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i;
    }

    return -1;
}

/**
 * @brief Returns the index of the first occurrence of an element in the array using binary search algorithm.
 * 
 * @param value Number to be searched in the array.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * 
 * @return Index of @p value in the array, if found; otherwise, -1.
 * @return -2, if @p arr is null or if @p size is a non-negative integer.
 * @return -3, if @p arr is not sorted in ascending order.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * int sorted_arr[] = {1, 2, 3, 4, 5};
 * 
 * binarySearch(3, arr, 5); // Returns -3
 * binarySearch(2, sorted_arr, 5); // Returns 1
 * binarySearch(6, sorted_arr, 5); // Returns -1
 * @endcode
 */
int binarySearch(const int value, const int arr[], const int size) {
    if (arr == NULL) {
        return -2;
    }
    if (size <= 0) {
        return -2;
    }
    if (!isSorted(arr, size)) {
        return -3;
    }

    if (value > arr[size-1] || value < arr[0]) {
        return -1;
    }

    int left_idx, mid_idx, right_idx;
    left_idx = 0;
    right_idx = size - 1;

    do {
        mid_idx = left_idx + ((right_idx - left_idx) / 2);

        if (arr[mid_idx] == value) {
            return mid_idx;
        }
        else if (arr[mid_idx] > value) {
            right_idx = mid_idx - 1;
        }
        else if (arr[mid_idx] < value) {
            left_idx = mid_idx + 1;
        }
    } while (left_idx <= right_idx);

    return -1;
}
