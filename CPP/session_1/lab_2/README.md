# Dynamic Array (Vector) Implementation in C

This C program demonstrates a basic implementation of a dynamic array using structures and functions.

The dynamic array allows for inserting elements at specified positions, deleting elements,

and dynamically extending its size when necessary.

## Files

1- main.c: Contains the main program with the implementation of dynamic array operations.

2- README.md: This file, providing an overview and usage instructions.

## Features

1- Initialization: Initializes a dynamic array with a user-defined size.

2- Insertion: Inserts an element at a specified position in the array.

3- Deletion: Deletes an element from a specified position in the array.

4- Capacity Management: Automatically extends the array size when the current capacity is reached.

## Usage

1- Compile the program

Compile the program using a C compiler such as gcc:

	gcc main.c -o app.exe

2- Run the Program:

Execute the compiled program:

	./app.exe
	
3- Follow the prompts to input the size of the dynamic array and perform insertion and deletion operations.

## Functions

1- initializeDynamicArray: Initializes the dynamic array with user-defined size.

2- insertElement: Inserts an element at a specified position in the array.

3- deleteElement: Deletes an element from a specified position in the array.

4- isArrayFull: Checks if the dynamic array is full.

5- extendArray: Extends the size of the dynamic array when it's full.

6- shiftArray: Shifts elements in the array to accommodate insertions or deletions.

7- displayArray: Displays all elements currently stored in the array.
