#include "sorting.h"

// Global step counter
long long steps = 0;

// Common utility functions (defined only here)
void swap(int *first_number, int *second_number) {
	steps++;
	int temp = *first_number;
	*first_number = *second_number;
	*second_number = temp;
}

void printArray(int array[], int length) {
	printf("Array elements: ");
	for(int i = 0; i < length && i < 20; i++) { // Show only first 20 elements
		printf("%d ", array[i]);
	}
	if(length > 20) printf("...");
	printf("\n");
}

void copyArray(int source[], int dest[], int n) {
	for(int i = 0; i < n; i++) {
		dest[i] = source[i];
	}
}

void generateRandomArray(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = rand() % 1000; // Random numbers between 0-999
	}
}

// Wrapper functions for your algorithms that need different signatures
void mergeSort(int array[], int n) {
	steps = 0;
	mergesort(array, 0, n-1);
}

void quickSort(int array[], int n) {
	steps = 0;
	quicksort(array, 0, n-1);
}

void displayMenu() {
	printf("\n=== SORTING ALGORITHM COMPARATOR ===\n");
	printf("1. Bubble Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Insertion Sort\n");
	printf("4. Merge Sort\n");
	printf("5. Quick Sort\n");
	printf("6. Radix Sort\n");
	printf("7. Compare All Algorithms\n");
	printf("8. Test with Custom Array\n");
	printf("9. Exit\n");
	printf("Choose an option (1-9): ");
}

int main() {
	int choice, size;
	int *originalArray = NULL, *tempArray = NULL;
	clock_t start, end;
	double cpu_time_used;

	srand(time(NULL));

	printf("Enter the size of array: ");
	scanf("%d", &size);

	if(size <= 0) {
		printf("Invalid array size!\n");
		return 1;
	}

	// Allocate memory for arrays
	originalArray = (int*)malloc(size * sizeof(int));
	tempArray = (int*)malloc(size * sizeof(int));

	if(originalArray == NULL || tempArray == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}

	// Generate initial random array
	generateRandomArray(originalArray, size);

	printf("Generated random array of size %d\n", size);

	do {
		displayMenu();
		scanf("%d", &choice);

		if(choice >= 1 && choice <= 6) {
			// Copy original array to temp array for sorting
			copyArray(originalArray, tempArray, size);

			printf("\nOriginal array (first 10 elements): ");
			for(int i = 0; i < (size < 10 ? size : 10); i++) {
				printf("%d ", tempArray[i]);
			}
			printf("\n");

			start = clock();
			long long initial_steps = steps;

			switch(choice) {
			case 1:
				printf("Performing Bubble Sort...\n");
				bubble_sort(tempArray, size);
				break;
			case 2:
				printf("Performing Selection Sort...\n");
				selection_sort(tempArray, size);
				break;
			case 3:
				printf("Performing Insertion Sort...\n");
				insertion_sort(tempArray, size);
				break;
			case 4:
				printf("Performing Merge Sort...\n");
				mergeSort(tempArray, size);
				break;
			case 5:
				printf("Performing Quick Sort...\n");
				quickSort(tempArray, size);
				break;
			case 6:
				printf("Performing Radix Sort...\n");
				radixsort(tempArray, size);
				break;
			}

			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			long long steps_taken = steps - initial_steps;

			printf("Sorted array (first 10 elements): ");
			for(int i = 0; i < (size < 10 ? size : 10); i++) {
				printf("%d ", tempArray[i]);
			}
			printf("\n");

			printf("Number of steps: %lld\n", steps_taken);
			printf("Time taken: %f seconds\n", cpu_time_used);

			// Verify if array is sorted
			int is_sorted = 1;
			for(int i = 1; i < size; i++) {
				if(tempArray[i] < tempArray[i-1]) {
					is_sorted = 0;
					break;
				}
			}
			printf("Array is %s\n", is_sorted ? "properly sorted" : "NOT properly sorted!");

		} else if(choice == 7) {
			// Compare all algorithms
			printf("\n=== COMPARING ALL SORTING ALGORITHMS ===\n");
			printf("Array size: %d\n\n", size);

			int *testArrays[6];
			for(int i = 0; i < 6; i++) {
				testArrays[i] = (int*)malloc(size * sizeof(int));
				copyArray(originalArray, testArrays[i], size);
			}

			char *algorithm_names[] = {
				"Bubble Sort", "Selection Sort", "Insertion Sort",
				"Merge Sort", "Quick Sort", "Radix Sort"
			};

			void (*sort_functions[])(int[], int) = {
				bubble_sort, selection_sort, insertion_sort,
				mergeSort, quickSort, radixsort
			};

			printf("%-20s %-15s %-15s %-10s\n",
			       "Algorithm", "Steps", "Time (s)", "Status");
			printf("------------------------------------------------------------\n");

			for(int i = 0; i < 6; i++) {
				copyArray(originalArray, testArrays[i], size);

				start = clock();
				long long initial_steps = steps;
				sort_functions[i](testArrays[i], size);
				end = clock();

				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
				long long steps_taken = steps - initial_steps;

				// Verify sorting
				int is_sorted = 1;
				for(int j = 1; j < size; j++) {
					if(testArrays[i][j] < testArrays[i][j-1]) {
						is_sorted = 0;
						break;
					}
				}

				printf("%-20s %-15lld %-15f %-10s\n",
				       algorithm_names[i], steps_taken, cpu_time_used,
				       is_sorted ? "b Sorted" : "b Failed");

				free(testArrays[i]);
			}

		} else if(choice == 8) {
			// Custom array input
			printf("Enter %d numbers separated by spaces: ", size);
			for(int i = 0; i < size; i++) {
				scanf("%d", &originalArray[i]);
			}
			printf("Custom array set successfully!\n");

		} else if(choice == 9) {
			printf("Exiting program...\n");
		} else {
			printf("Invalid choice! Please try again.\n");
		}

	} while(choice != 9);

	// Cleanup
	free(originalArray);
	free(tempArray);

	return 0;
}