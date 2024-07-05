#include <stdio.h>
#include <stdlib.h>

// Define the DynamicArray structure
struct DynamicArray {
    unsigned int *array;   // Dynamic array
    unsigned int size;     // Maximum size of the array
    unsigned int capacity; // Current number of elements in the array
};

// Define enumeration for Boolean values
typedef enum {
    FALSE,  // Indicates a failed state
    TRUE    // Indicates a successful state
} Boolean;

// Define enumeration for Shift types
typedef enum {
    InsertShift,  // Shift type for inserting elements
    DeleteShift   // Shift type for deleting elements
} ShiftType;

// Function declarations
Boolean initializeDynamicArray(struct DynamicArray *dynArray);
Boolean insertElement(struct DynamicArray *dynArray, unsigned int element, unsigned int position);
void shiftArray(struct DynamicArray *dynArray, unsigned int start_pos, ShiftType shift_type);
Boolean isArrayFull(struct DynamicArray *dynArray);
Boolean extendArray(struct DynamicArray *dynArray);
void deleteElement(struct DynamicArray *dynArray, unsigned int position);
void displayArray(struct DynamicArray *dynArray);

int main() {
    struct DynamicArray dynArray;

    // User input for array size
    printf("Enter the size of the dynamic array: ");
    scanf("%u", &dynArray.size);

    // Initialize the dynamic array
    Boolean status = initializeDynamicArray(&dynArray);

    // Insert at the beginning
    insertElement(&dynArray, 1, 1);
    // Insert at the end
    insertElement(&dynArray, 2, 2);
    insertElement(&dynArray, 3, 3);
    // Insert at a specific position
    insertElement(&dynArray, 10, 2); // capacity +1 = size
    // Display the array elements
    displayArray(&dynArray);
    // Delete at a specific position
    deleteElement(&dynArray, 2);
    // Display array elements
    displayArray(&dynArray);

    // Free allocated memory (not shown in the snippet)
    free(dynArray.array);

    return 0;
}

/**
 * @brief Initialize the dynamic array
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @return Boolean Returns true if initialization is successful, otherwise false
 */
Boolean initializeDynamicArray(struct DynamicArray *dynArray) {
    Boolean status = FALSE;
    // Dynamic allocation for array based on user size
    dynArray->array = (unsigned int *)malloc(sizeof(unsigned int) * dynArray->size);
    if (NULL == dynArray->array) {
        printf("Memory allocation failed\n");
    } else {
        status = TRUE;
    }
    // Initialize capacity to 0 at the beginning
    dynArray->capacity = 0;

    return status;
}

/**
 * @brief Insert an element into the array at a specified position
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @param element Element to be inserted
 * @param position Position to insert the element (1-based index)
 * @return Boolean Returns true if insertion is successful, otherwise false
 */
Boolean insertElement(struct DynamicArray *dynArray, unsigned int element, unsigned int position) {
    Boolean status = FALSE;
    // Check if array is full
    status = isArrayFull(dynArray);
    if (true == status) {
        // If array is full, call the extend function (extend size *2)
        Boolean extendStatus = extendArray(dynArray);
        if (true == extendStatus) {
            // If extending is successful, then insert the element
            dynArray->array[position - 1] = element;
            dynArray->capacity++;
        } else {
            printf("Extending array failed\n");
        }
    } else if (false == status) {
        // If array is not full, insert element directly
        dynArray->array[position - 1] = element;
        dynArray->capacity++;
        status = TRUE;
    }

    return status;
}

/**
 * @brief Check if the array is full
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @return Boolean Returns true if the array is full, otherwise false
 */
Boolean isArrayFull(struct DynamicArray *dynArray) {
    if(dynArray->capacity == dynArray->size)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief Shift elements in the array to make space or remove an element
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @param start_pos Position to start shifting from (1-based index)
 * @param shift_type Type of shift (InsertShift or DeleteShift)
 */
void shiftArray(struct DynamicArray *dynArray, unsigned int start_pos, ShiftType shift_type) {
    if (InsertShift == shift_type) {
        for (unsigned int i = dynArray->capacity; i > start_pos - 1; i--) {
            dynArray->array[i] = dynArray->array[i - 1];
        }
    } else if (DeleteShift == shift_type) {
        for (unsigned int i = start_pos - 1; i < dynArray->capacity - 1; i++) {
            dynArray->array[i] = dynArray->array[i + 1];
        }
    }
}

/**
 * @brief Display the elements of the array
 * 
 * @param dynArray Pointer to the DynamicArray structure
 */
void displayArray(struct DynamicArray *dynArray) {
    for (unsigned int i = 0; i < dynArray->capacity; i++) {
        printf("%u\t", dynArray->array[i]);
    }
    printf("\n");
}

/**
 * @brief Insert an element into the array at a specified position
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @param element Element to be inserted
 * @param position Position to insert the element (1-based index)
 */
void insertAtPosition(struct DynamicArray *dynArray, unsigned int element, unsigned int position) {
    // Array is not full and can insert
    if ((position <= dynArray->size) && (position - 1 == dynArray->capacity)) {
        // Insert at end
        dynArray->array[position - 1] = element;
        dynArray->capacity++;
    } else if ((position <= dynArray->size) && (position < dynArray->capacity)) {
        // Shift because of inserting in the middle of array
        shiftArray(dynArray, position, InsertShift);
        // Then insert element at the position
        dynArray->array[position - 1] = element;
        dynArray->capacity++;
    }
}

/**
 * @brief Extend the size of the array
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @return Boolean Returns true if extension is successful, otherwise false
 */
Boolean extendArray(struct DynamicArray *dynArray) {
    Boolean extendStatus = FALSE;
    dynArray->array = (unsigned int *)realloc(dynArray->array, (dynArray->size * 2) * sizeof(unsigned int));
    if (NULL == dynArray->array) {
        extendStatus = FALSE;
    } else {
        extendStatus = TRUE;
        dynArray->size *= 2;
    }
    return extendStatus;
}

/**
 * @brief Delete an element from the array at a specified position
 * 
 * @param dynArray Pointer to the DynamicArray structure
 * @param position Position to delete the element from (1-based index)
 */
void deleteElement(struct DynamicArray *dynArray, unsigned int position) {
    if ((position <= dynArray->size) && (position == dynArray->capacity)) {
        dynArray->array[position - 1] = 0;
        dynArray->capacity--;
    } else if ((position <= dynArray->size) && (position < dynArray->capacity)) {
        // Shift because of deleting in the middle of array
        shiftArray(dynArray, position, DeleteShift);
        dynArray->capacity--;
    }
}