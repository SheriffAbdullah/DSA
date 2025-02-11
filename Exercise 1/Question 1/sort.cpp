
/**
 * @file sort.cpp
 * @brief Sorting algorithms - Bubble Sort, Insertion Sort, Selection Sort.
 * 
 * Program to sort a user-defined array.
 * 
 * @author Abdullah Sheriff
 * @date Februrary 8th, 2025
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using std::numeric_limits; using std::streamsize; // For handling input exceptions
using std::bad_alloc;

// ====== Utilities ======
void swapIntegers(int*, int*);
int findMinIdx(const int[], const int);
int findMaxIdx(const int[], const int);
bool isInvalidInput();

// ====== Array Utilities ======
int getArrayLengthInput();
int* getArrayInput(const int);
int* deepCopyArray(const int[], const int);

// ====== Printing Utilities ======
void printArray(const int[], const int);

// ====== Sorting Functions ======
void bubbleSort(int[], const int, bool desc=false);
void insertionSort(int[], const int, bool desc=false);
void selectionSort(int[], const int, bool desc=false);

int main() {
    int length;
    unsigned int user_choice;
    int* arr; int* arr_copy;

    length = getArrayLengthInput();
    arr = getArrayInput(length);
    cout << endl;
    
    do {
        arr_copy = deepCopyArray(arr, length);

        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Exit" << endl;
        cout << endl;

        do {
            cout << "Enter your choice (1-4): ";
            cin >> user_choice;

            if (isInvalidInput() || user_choice < 1 || user_choice > 4) {
                cout << "Invalid input. Please enter an integer between (1-4)." << endl;
            } 
            else {
                break;
            }
        } while (true);
        cout << endl;

        switch(user_choice) {
            case 1:
                bubbleSort(arr, length);
                printArray(arr, length);
                cout << endl;
                break;
            case 2:
                selectionSort(arr, length);
                printArray(arr, length);
                cout << endl;
                break;
            case 3:
                insertionSort(arr, length);
                printArray(arr, length);
                cout << endl;
                break;
            case 4:
                delete[] arr;
                delete[] arr_copy;
                return 0;
        }
    } while (true);
}

/**
 * @brief Swaps two integers.
 * 
 * @param ptr1 Pointer to the first integer.
 * @param ptr2 Pointer to the second integer.
 * 
 * @note @p ptr1 & @p ptr2 must be non-null pointers for the swap to occur.
 * 
 * @code
 * int num1 = 5;
 * int num2 = 10;
 * swapIntegers(&num1, &num2);
 * // num1 is 10 & num2 is 5.
 * @endcode
 */
void swapIntegers(int* ptr1, int* ptr2) {
    if (!ptr1 || !ptr2) {
        return;
    }

    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

/**
 * @brief Returns the index of the minimum element in the array.
 * 
 * @param arr Pointer to the array.
 * @param length Number of elements in the array.
 * 
 * @return Index of the minimum element in the array.
 * @return -2, if @p arr is null or if @p length is a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * int index = findMinIdx(arr, 5); // Returns 1
 * @endcode
 */
int findMinIdx(const int arr[], const int length) {
    if (!arr) {
        return -2;
    }
    if (length <= 0) {
        return -2;
    }
    if (length == 1) {
        return 0;
    }
    
    int min_idx = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    return min_idx;
}

/**
 * @brief Returns the index of the maximum element in the array.
 * 
 * @param arr Pointer to the array.
 * @param length Number of elements in the array.
 * 
 * @return Index of the maximum element in the array.
 * @return -2, if @p arr is null or if @p length is a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * int index = findMaxIdx(arr, 5); // Returns 0
 * @endcode
 */
int findMaxIdx(const int arr[], const int length) {
    if (!arr) {
        return -2;
    }
    if (length <= 0) {
        return -2;
    }
    if (length == 1) {
        return 0;
    }
    
    int max_idx = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }

    return max_idx;
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
 * @brief Returns a value for length of an array and validates input.
 * 
 * @code
 * int length = getArrayLengthInput();
 * 
 * // Output: "Enter a positive array length: 5" 
 * // Returns 5
 * @endcode
 */
int getArrayLengthInput() {
    int length;

    do {
        cout << "Enter a positive array length: ";
        cin >> length;

        if (isInvalidInput() || length < 1) {
            cout << "Invalid input. Please enter a valid integer greater than (0)." << endl;
        }
        else {
            return length;
        }
    } while (true);
}

/**
 * @brief Returns an array and validates its elements.
 * 
 * @param length Number of elements in the array.
 * 
 * @note @p length must be a non-negative integer.
 * 
 * @code
 * int length = 5;
 * int* arr = getArrayInput(length);
 * 
 * // Output: "Enter 5 integers separated by spaces: 5 4 3 2 1" 
 * // Returns {5, 4, 3, 2, 1}
 * @endcode
 */
int* getArrayInput(const int length) {
    if (length <= 0) {
        return nullptr;
    }

    int* arr;

    try {
        arr = new int[length];
    } catch (const bad_alloc& e) {
        return nullptr;
    }

    do {
        cout << "Enter " << length << " integers separated by spaces: ";

        for (int i = 0; i < length; i++) {
            cin >> arr[i];
        }

        if (isInvalidInput()) {
            cout << "Invalid input. Enter only " << length << " integers separated by spaces." << endl;
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
 * @param length Number of elements in the array.
 * 
 * @return Pointer to a copy of the array.
 * 
 * @note @p arr must be a non-null pointer, and @p length must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * int arr_copy = deepCopyArray(arr, 5); // arr_copy = {5, 1, 2, 3, 4}
 * @endcode
 */
int* deepCopyArray(const int arr[], const int length) {
    if (!arr) {
        return nullptr;
    }
    if (length <= 0) {
        return nullptr;
    }

    int* arr_copy;

    try {
        arr_copy = new int[length];
    } catch (const bad_alloc& e) {
        return nullptr;
    }

    for (int i = 0; i < length; i++) {
        arr_copy[i] = arr[i];
    }

    return arr_copy;
}

/**
 * @brief Prints the elements in an array.
 * 
 * @param arr Pointer to the array.
 * @param length Number of elements in the array.
 * 
 * @note @p arr must be a non-null pointer, and @p length must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * printArray(arr, 5) // Output: "Array elements: 5 1 2 3 4"
 * @endcode
 */
void printArray(const int arr[], const int length) {
    if (!arr) {
        return;
    }
    if (length < 0) {
        return;
    }
    if (length == 0) {
        cout << "Array is empty." << endl;
    }

    cout << "Array elements: ";

    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

/**
 * @brief Sorts the array in ascending order using Bubble sort algorithm.
 * 
 * @param arr Pointer to the array.
 * @param length Number of elements in the array.
 * @param desc If true, sorts the array in descending order; otherwise, sorts it in ascending order. (default=false)
 * 
 * @note arr must be a non-null pointer, and length must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * 
 * bubbleSort(arr, 5);
 * // Sorted array: 1 2 3 4 5
 * 
 * bubbleSort(arr, 5, true);
 * // Sorted array: 5 4 3 2 1
 * @endcode
 */

void bubbleSort(int arr[], const int length, const bool desc) {
    /*
    In-place Bubble sort.
    */
    if (!arr) {
        return;
    }
    if (length <= 0) {
        return;
    }

    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (desc ? arr[j] < arr[j+1] : arr[j] > arr[j+1]) {
                swapIntegers(&arr[j], &arr[j+1]);
            }
        }
    }
}

/**
 * @brief Sorts the array in ascending order using Selection sort algorithm.
 * 
 * @param arr Pointer to the array.
 * @param length Number of elements in the array.
 * @param desc If true, sorts the array in descending order; otherwise, sorts it in ascending order. (default=false)
 * 
 * @note @p arr must be a non-null pointer, and @p length must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * 
 * selectionSort(arr, 5);
 * // Sorted array: 1 2 3 4 5
 * 
 * selectionSort(arr, 5, true);
 * // Sorted array: 5 4 3 2 1
 * @endcode
 */
void selectionSort(int arr[], const int length, const bool desc) {
    /*
    In-place Selection sort.
    */
    if (!arr) {
        return;
    }
    if (length <= 0) {
        return;
    }

    int swapIdx;

    for (int i = 0; i < length-1; i++) {
        if (desc) {
            swapIdx = findMaxIdx(arr+i, length-i) + i;
        } else {
            swapIdx = findMinIdx(arr+i, length-i) + i;
        }

        swapIntegers(&arr[swapIdx], &arr[i]);
    }
}

/**
 * @brief Sorts the array in ascending order using Insertion sort algorithm.
 * 
 * @param arr Pointer to the array.
 * @param length Number of elements in the array.
 * @param desc If true, sorts the array in descending order; otherwise, sorts it in ascending order. (default=false)
 * 
 * @note @p arr must be a non-null pointer, and @p length must be a non-negative integer.
 * 
 * @code
 * int arr[] = {5, 1, 2, 3, 4};
 * 
 * insertionSort(arr, 5);
 * // Sorted array: 1 2 3 4 5
 * 
 * insertionSort(arr, 5, true);
 * // Sorted array: 5 4 3 2 1
 * @endcode
 */
void insertionSort(int arr[], const int length, const bool desc) {
    /*
    In-place Insertion sort.
    */
    if (!arr) {
        return;
    }
    if (length <= 0) {
        return;
    }

    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0; j--) {
            if (desc ? arr[j] < arr[j-1] : arr[j] > arr[j-1]) {
                break;
            }
            else {
                swapIntegers(&arr[j], &arr[j-1]);
            }
        }
    }
}


// class person form a function person <- This line was written by Vrishin Vigneshwar <heartFaceEmoji>