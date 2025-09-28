#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to count steps
extern long long steps;

// Function declarations from your files
void bubble_sort(int array[], int length);
void selection_sort(int array[], int length);
void insertion_sort(int array[], int length);
void mergesort(int array[], int low, int high);
void quicksort(int array[], int low, int high);
void radixsort(int array[], int n);

// Wrapper functions for consistent interface
void mergeSort(int array[], int n);
void quickSort(int array[], int n);

// Utility functions
void swap(int *first_number, int *second_number);
void printArray(int array[], int length);
void copyArray(int source[], int dest[], int n);
void generateRandomArray(int arr[], int n);
void displayMenu();

#endif
