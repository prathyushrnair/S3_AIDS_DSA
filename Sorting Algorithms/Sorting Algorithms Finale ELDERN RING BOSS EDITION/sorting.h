#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to count steps
extern long long steps;

// Function declarations - using exact function names from your files
void bubble_sort(int array[], int length);
void selection_sort(int array[], int length);
void insertion_sort(int array[], int length);
void mergesort(int array[], int low, int high);  // Note: lowercase 'm'
void quicksort(int array[], int low, int high);  // Note: lowercase 'q'
void radixsort(int array[], int n);

// Wrapper functions for consistent interface (will be defined in menu.c)
void mergeSort(int array[], int n);  // Note: uppercase 'M'
void quickSort(int array[], int n);   // Note: uppercase 'Q'

// Common utility functions (defined in menu.c only)
void swap(int *first_number, int *second_number);
void printArray(int array[], int length);
void copyArray(int source[], int dest[], int n);
void generateRandomArray(int arr[], int n);
void displayMenu();

#endif