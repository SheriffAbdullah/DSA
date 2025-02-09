
/**
 * @file sort.h
 * @brief Sorting algorithms - Bubble Sort, Insertion Sort, Selection Sort.
 * 
 * Provides function declarations for sorting algorithms.
 * 
 * @author Abdullah Sheriff
 * @date Februrary 8th, 2025
 */

#pragma once

// ====== Utilities ======
void swapIntegers(int*, int*);
int findMinIdx(const int[], const int);
int findMaxIdx(const int[], const int);

// ====== Sorting Functions ======
void bubbleSort(int[], const int, bool desc=false);
void insertionSort(int[], const int, bool desc=false);
void selectionSort(int[], const int, bool desc=false);