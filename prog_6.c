#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify for max heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Heapify for min heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Build max heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Build min heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Display heap level-wise
void displayHeap(int arr[], int n) {
    int level = 0;
    int count = 0;
    int levelSize = 1;
    
    printf("\nHeap structure (level-wise):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count++;
        
        if (count == levelSize) {
            printf("\n");
            level++;
            levelSize *= 2;
            count = 0;
        }
    }
    if (count != 0) printf("\n");
}

// Insert into max heap
void insertMaxHeap(int arr[], int *n, int value) {
    if (*n >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    
    (*n)++;
    int i = *n - 1;
    arr[i] = value;
    
    // Fix max heap property
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d into max heap\n", value);
}

// Insert into min heap
void insertMinHeap(int arr[], int *n, int value) {
    if (*n >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    
    (*n)++;
    int i = *n - 1;
    arr[i] = value;
    
    // Fix min heap property
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d into min heap\n", value);
}

// Delete max (root) from max heap
int deleteMax(int arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }
    
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
    
    return root;
}

// Delete min (root) from min heap
int deleteMin(int arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }
    
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    
    return root;
}

int main() {
    int arr[MAX], n, choice, value, heapType;
    
    printf("Min Heap and Max Heap Implementation\n");
    printf("=====================================\n\n");
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    displayArray(arr, n);
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Build Max Heap\n");
        printf("2. Build Min Heap\n");
        printf("3. Insert into heap\n");
        printf("4. Delete from heap\n");
        printf("5. Display array\n");
        printf("6. Display heap structure\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                buildMaxHeap(arr, n);
                printf("Max Heap: ");
                displayArray(arr, n);
                heapType = 1;
                break;
                
            case 2:
                buildMinHeap(arr, n);
                printf("Min Heap: ");
                displayArray(arr, n);
                heapType = 2;
                break;
                
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (heapType == 1) {
                    insertMaxHeap(arr, &n, value);
                } else if (heapType == 2) {
                    insertMinHeap(arr, &n, value);
                } else {
                    printf("Please build a heap first!\n");
                }
                break;
                
            case 4:
                if (heapType == 1) {
                    value = deleteMax(arr, &n);
                    if (value != -1) printf("Deleted max: %d\n", value);
                } else if (heapType == 2) {
                    value = deleteMin(arr, &n);
                    if (value != -1) printf("Deleted min: %d\n", value);
                } else {
                    printf("Please build a heap first!\n");
                }
                break;
                
            case 5:
                printf("Array: ");
                displayArray(arr, n);
                break;
                
            case 6:
                displayHeap(arr, n);
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
