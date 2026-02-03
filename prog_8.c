#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

// Global counters
long long comparisons = 0;
long long swaps = 0;

// Reset counters
void resetCounters() {
    comparisons = 0;
    swaps = 0;
}

// Swap two elements
void swap(int *a, int *b) {
    swaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    resetCounters();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    resetCounters();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    resetCounters();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        swaps++;
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        swaps++;
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        swaps++;
        j++;
        k++;
    }
}

// Merge Sort helper
void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Merge Sort
void mergeSort(int arr[], int n) {
    resetCounters();
    mergeSortHelper(arr, 0, n - 1);
}

// Generate random array
void generateRandomArray(int arr[], int n, int max_val) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val + 1;
    }
}

// Copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Display array
void displayArray(int arr[], int n) {
    if (n > 20) {
        printf("First 10: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("... Last 10: ");
        for (int i = n - 10; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// Verify if array is sorted
int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, choice, maxVal;
    int original[MAX], temp[MAX];
    
    srand(time(NULL));
    
    printf("Sorting Algorithms with Comparison and Swap Counts\n");
    printf("===================================================\n\n");
    
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);
    
    if (n > MAX || n <= 0) {
        printf("Invalid size! Must be between 1 and %d\n", MAX);
        return 1;
    }
    
    printf("Enter maximum value for random numbers: ");
    scanf("%d", &maxVal);
    
    // Generate random array
    generateRandomArray(original, n, maxVal);
    
    printf("\nGenerated random array:\n");
    displayArray(original, n);
    
    while (1) {
        printf("\n--- Sorting Algorithm Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Generate new random array\n");
        printf("6. Compare all algorithms\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                copyArray(original, temp, n);
                printf("\nSorting using Bubble Sort...\n");
                bubbleSort(temp, n);
                printf("Sorted: ");
                displayArray(temp, n);
                printf("Comparisons: %lld, Swaps: %lld\n", comparisons, swaps);
                printf("Verified: %s\n", isSorted(temp, n) ? "Correct" : "Incorrect");
                break;
                
            case 2:
                copyArray(original, temp, n);
                printf("\nSorting using Selection Sort...\n");
                selectionSort(temp, n);
                printf("Sorted: ");
                displayArray(temp, n);
                printf("Comparisons: %lld, Swaps: %lld\n", comparisons, swaps);
                printf("Verified: %s\n", isSorted(temp, n) ? "Correct" : "Incorrect");
                break;
                
            case 3:
                copyArray(original, temp, n);
                printf("\nSorting using Insertion Sort...\n");
                insertionSort(temp, n);
                printf("Sorted: ");
                displayArray(temp, n);
                printf("Comparisons: %lld, Swaps: %lld\n", comparisons, swaps);
                printf("Verified: %s\n", isSorted(temp, n) ? "Correct" : "Incorrect");
                break;
                
            case 4:
                copyArray(original, temp, n);
                printf("\nSorting using Merge Sort...\n");
                mergeSort(temp, n);
                printf("Sorted: ");
                displayArray(temp, n);
                printf("Comparisons: %lld, Swaps: %lld\n", comparisons, swaps);
                printf("Verified: %s\n", isSorted(temp, n) ? "Correct" : "Incorrect");
                break;
                
            case 5:
                generateRandomArray(original, n, maxVal);
                printf("\nNew random array generated:\n");
                displayArray(original, n);
                break;
                
            case 6:
                printf("\n=== Comparison of All Algorithms ===\n");
                printf("Array size: %d\n\n", n);
                
                // Bubble Sort
                copyArray(original, temp, n);
                bubbleSort(temp, n);
                printf("Bubble Sort    - Comparisons: %lld, Swaps: %lld\n", 
                       comparisons, swaps);
                
                // Selection Sort
                copyArray(original, temp, n);
                selectionSort(temp, n);
                printf("Selection Sort - Comparisons: %lld, Swaps: %lld\n", 
                       comparisons, swaps);
                
                // Insertion Sort
                copyArray(original, temp, n);
                insertionSort(temp, n);
                printf("Insertion Sort - Comparisons: %lld, Swaps: %lld\n", 
                       comparisons, swaps);
                
                // Merge Sort
                copyArray(original, temp, n);
                mergeSort(temp, n);
                printf("Merge Sort     - Comparisons: %lld, Swaps: %lld\n", 
                       comparisons, swaps);
                break;
                
            case 7:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
