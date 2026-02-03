# Documentation for prog_8.c

## Problem Statement
Generate random integers and sort them using user-selected sorting algorithms (Bubble, Selection, Insertion, Merge Sort). Display comparison and swap counts for performance analysis.

## Sorting Algorithms Implemented

### 1. Bubble Sort
- **Description**: Repeatedly swaps adjacent elements if they are in wrong order
- **Time Complexity**: 
  - Best: O(n) - already sorted
  - Average: O(n²)
  - Worst: O(n²)
- **Space**: O(1)
- **Stable**: Yes

### 2. Selection Sort
- **Description**: Finds minimum element and places it at beginning
- **Time Complexity**: O(n²) in all cases
- **Space**: O(1)
- **Stable**: No (in basic implementation)

### 3. Insertion Sort
- **Description**: Builds sorted array one element at a time
- **Time Complexity**:
  - Best: O(n) - already sorted
  - Average: O(n²)
  - Worst: O(n²)
- **Space**: O(1)
- **Stable**: Yes

### 4. Merge Sort
- **Description**: Divide and conquer - divides array, sorts, then merges
- **Time Complexity**: O(n log n) in all cases
- **Space**: O(n) for temporary arrays
- **Stable**: Yes

## Key Features

### Performance Tracking
- **Comparisons**: Counts element comparisons
- **Swaps**: Counts element movements/swaps
- Global counters track operations for analysis

### Functions

#### `void bubbleSort(int arr[], int n)`
Implements bubble sort with comparison and swap counting.

#### `void selectionSort(int arr[], int n)`
Implements selection sort with operation counting.

#### `void insertionSort(int arr[], int n)`
Implements insertion sort with operation counting.

#### `void mergeSort(int arr[], int n)`
Implements merge sort with operation counting.

#### `void generateRandomArray(int arr[], int n, int max_val)`
Generates array of n random integers between 1 and max_val.

#### `int isSorted(int arr[], int n)`
Verifies if array is sorted correctly.

## Performance Comparison
For array of size n:

| Algorithm      | Best Case | Average Case | Worst Case | Space |
|----------------|-----------|--------------|------------|-------|
| Bubble Sort    | O(n)      | O(n²)        | O(n²)      | O(1)  |
| Selection Sort | O(n²)     | O(n²)        | O(n²)      | O(1)  |
| Insertion Sort | O(n)      | O(n²)        | O(n²)      | O(1)  |
| Merge Sort     | O(n log n)| O(n log n)   | O(n log n) | O(n)  |

## Sample Output
```
Enter number of elements: 10
Enter maximum value: 100

Generated: 45 23 67 12 89 34 56 78 90 21

--- Comparison of All Algorithms ---

Bubble Sort    - Comparisons: 45, Swaps: 24
Selection Sort - Comparisons: 45, Swaps: 9
Insertion Sort - Comparisons: 24, Swaps: 24
Merge Sort     - Comparisons: 19, Swaps: 30
```

## Observations
- Merge Sort has best time complexity O(n log n)
- Bubble Sort has most swaps for random data
- Selection Sort has fewest swaps
- Insertion Sort performs well on nearly sorted data
