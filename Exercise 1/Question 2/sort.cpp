
/**
 * @file sort.cpp
 * @brief Sorting algorithms - Bubble Sort, Insertion Sort, Selection Sort.
 * 
 * Provides function definitions for sorting algorithms.
 * 
 * @author Abdullah Sheriff
 * @date Februrary 8th, 2025
 */

#include <iostream>
#include "sort.h"

// ====== Utilities ======
void swapIntegers(int*, int*);
int findMinIdx(const int[], const int);
int findMaxIdx(const int[], const int);

// ====== Sorting Functions ======
void bubbleSort(int[], const int, bool desc);
void insertionSort(int[], const int, bool desc);
void selectionSort(int[], const int, bool desc);


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
 * @brief Sorts the array in ascending order using Bubble sort algorithm.
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