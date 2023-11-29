# Dynamic Array Implementation in C

This C program provides a simple implementation of a dynamic array with various functions for manipulation.

## Dynamic Array Structure

The `Dynamic_Array` structure includes:

- `array`: A pointer to the dynamic array.
- `size`: The current number of elements in the array.
- `capacity`: The current capacity of the array.

```c
typedef struct {
    int *array;
    int size;
    int capacity;
} Dynamic_Array;

## Functions

### `initialize(Dynamic_Array *arr, int initial_capacity)`
- Initializes a dynamic array with the given initial capacity.

### `resize(Dynamic_Array *arr, int new_capacity)`
- Resizes the dynamic array to the specified new capacity.

### `shrink(Dynamic_Array *arr)`
- Reduces the size of the array if necessary.

### `insert(Dynamic_Array *arr, int element)`
- Inserts an element at the end of the array.

### `deleteByIndex(Dynamic_Array *arr, int index)`
- Deletes an element at the specified index.

### `deleteByValue(Dynamic_Array *arr, int value)`
- Deletes the first occurrence of an element with the given value.

### `accessByIndex(Dynamic_Array *arr, int index)`
- Accesses the element at the specified index.

### `getSize(Dynamic_Array *arr)`
- Gets the current size of the array.

### `getCapacity(Dynamic_Array *arr)`
- Gets the current capacity of the array.

### `insertAtIndex(Dynamic_Array *arr, int index, int element)`
- Inserts an element at the specified index.

### `sort(Dynamic_Array *arr)`
- Sorts the elements in the array using bubble sort.

### `search(Dynamic_Array *arr, int value)`
- Searches for an element with the given value.

### `printArray(Dynamic_Array *arr)`
- Prints the elements of the array.

### `freeArray(Dynamic_Array *arr)`
- Frees the dynamically allocated memory for the array.

## Integration

To integrate the dynamic array library into other projects, follow these steps:

1. Include the `dynamic_array.c` and `dynamic_array.h` files in your project.
2. Call the necessary functions from `dynamic_array.h` based on your requirements.

## Example Usage

```c
int main() {
    // Create a dynamic array
    Dynamic_Array example_array;
    
    // Initialize the array with an initial capacity
    initialize(&example_array, initial_capacity);
    
    // Insert elements into the array
    insert(&example_array, 10);
    insert(&example_array, 12);
    
    // ... (add more function calls as needed)
    
    // Free the dynamically allocated memory
    freeArray(&example_array);
    
    // Return 0 to indicate successful execution
    return 0;
}
