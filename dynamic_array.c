#include <stdio.h>
#include <stdlib.h>

int initial_capacity = 1;

typedef struct
{ // creating Dynamic_Array structure with arr, size and capacity properties
    int *array;
    int size;
    int capacity;
} Dynamic_Array;

void initialize(Dynamic_Array *arr, int initial_capacity)
{ // initializing wih provided capacity => work with dynamic memory
    arr->array = (int *)malloc(initial_capacity * sizeof(int));
    arr->size = 0; // initializing size to 0
    arr->capacity = initial_capacity;
}

void resize(Dynamic_Array *arr, int new_capacity)
{ // resizing with provided capacity
    arr->array = (int *)realloc(arr->array, new_capacity * sizeof(int));
    arr->capacity = new_capacity;
}

void shrink(Dynamic_Array *arr)
{ // compare and reduce size if necessary
    if (arr->size < arr->capacity / 4)
    {
        int new_capacity = arr->capacity / 2;
        resize(arr, new_capacity);
    }
}

void insert(Dynamic_Array *arr, int element)
{ // inserting element
    if (arr->size == arr->capacity)
    { // resize if necessary
        resize(arr, arr->capacity * 2);
    }
    arr->array[arr->size++] = element; // (push(el))
}

void deleteByIndex(Dynamic_Array *arr, int index)
{ // delete by index
    if (index < arr->size)
    {
        for (int i = index; i < arr->size - 1; ++i)
        {
            arr->array[i] = arr->array[i + 1]; // advance the value by one, starting from the index
        }
        --arr->size; // reduse size by one (pop())
        shrink(arr); // shrink if necessary
    }
}

void deleteByValue(Dynamic_Array *arr, int value)
{ // delete by value
    for (int i = 0; i < arr->size; ++i)
    {
        if (arr->array[i] == value)
        { // find the element by value and then delete
            deleteByIndex(arr, i);
            break;
        }
    }
    shrink(arr); // shrink if necessary
}

int accessByIndex(Dynamic_Array *arr, int index)
{
    if (index < arr->size)
    { // validiation of given index
        return arr->array[index];
    }
    else
    {
        return -1; // index is out-of-bounds
    }
}

int getSize(Dynamic_Array *arr)
{ // get size
    printf("Size of the array: %d\n", arr->size);
    return arr->size;
}

int getCapacity(Dynamic_Array *arr)
{ // get capacity
    printf("Capacity of the array: %d\n", arr->capacity);
    return arr->capacity;
}

void insertAtIndex(Dynamic_Array *arr, int index, int element)
{ // insertion at Index
    if (index <= arr->size)
    {
        if (arr->size == arr->capacity)
        {
            resize(arr, arr->capacity * 2);
        }
        for (int i = arr->size; i > index; --i)
        {
            arr->array[i] = arr->array[i - 1]; // shifting subsequent elements
        }
        arr->array[index] = element; // Allow inserting an element at a specified index
        ++arr->size;
        if (arr->size == arr->capacity)
        { // resize if necessary
            resize(arr, arr->capacity * 2);
        }
    }
    else
    {
        printf("Error: Index is out of bounds\n");
    }
}

void sort(Dynamic_Array *arr)
{ // sorting elements with bubble sort
    for (size_t i = 0; i < arr->size - 1; ++i)
    {
        for (size_t j = 0; j < arr->size - i - 1; ++j)
        {
            if (arr->array[j] > arr->array[j + 1])
            { // Swap elements if they are in the wrong order
                int temp = arr->array[j];
                arr->array[j] = arr->array[j + 1];
                arr->array[j + 1] = temp;
            }
        }
    }
}

int search(Dynamic_Array *arr, int value)
{ // Additional: searching element
    for (int i = 0; i < arr->size; ++i)
    {
        if (arr->array[i] == value)
        {
            printf("Element is found\n");
            return 1; // Return 1 to indicate the value is found
        }
    }
    printf("No such element\n");
    return 0; // Return 0 to indicate the value is not found
}

void printArray(Dynamic_Array *arr)
{ // Print array
    for (int i = 0; i < arr->size; ++i)
    {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

void freeArray(Dynamic_Array *arr)
{
    free(arr->array);
}

int main()
{
    Dynamic_Array example_array;
    initialize(&example_array, initial_capacity);
    insert(&example_array, 10);
    insert(&example_array, 12);
    insert(&example_array, 14);
    insert(&example_array, 14);
    insert(&example_array, 19);
    printArray(&example_array);
    getCapacity(&example_array);
    getSize(&example_array);
    // printf("--------------------------\n");
    // deleteByIndex(&example_array, 1);
    // deleteByIndex(&example_array, 1);
    // deleteByIndex(&example_array, 2);
    // deleteByIndex(&example_array, 1);
    // getCapacity(&example_array);
    // getSize(&example_array);
    printf("--------------------------\n");
    insertAtIndex(&example_array, 1, 90);
    insertAtIndex(&example_array, 2, 70);
    insert(&example_array, 19);
    insert(&example_array, 19);
    printArray(&example_array);
    getCapacity(&example_array);
    getSize(&example_array);
    printf("--------------------------\n");
    sort(&example_array);
    printArray(&example_array);
    printf("Element at index 7: %d\n", accessByIndex(&example_array, 7));

    freeArray(&example_array); // Free the dynamically allocated memory

    return 0;
}