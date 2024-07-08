# Simple Calculator C Application built using makefile

This project implements a simple calculator in C, allowing basic arithmetic operations based on user input.

It includes a Makefile to automate the compilation process.


## Project Structure


project/

├── src/
│   ├── add.c
│   ├── div.c
│   ├── main.c
│   ├── multi.c
│   └── sub.c
├── include/
│   ├── add.h
│   ├── div.h
│   ├── multi.h
│   └── sub.h
├── bin/
└── build/

1- src/: Contains the source '.c' files for different arithmetic operations and main.c.

2- include/: Contains the header '.h' files with function declarations.

3- bin/: Will contain the compiled object files (.o).

4- build/: Will contain the final executable (app).


## Files

main.c: Entry point of the application where user input is taken and operations are performed.

add.c, sub.c, multi.c, div.c: Implementations of addition, subtraction, multiplication, and division respectively.

add.h, sub.h, multi.h, div.h: Header files defining function prototypes for arithmetic operations.



## How to Compile

To compile the project, navigate to the project directory and simply run:

### make all

This will compile all .c files in src/, generate corresponding object files in bin/, 

and then link them to create the executable app in build/ .

## How to Run 

After compiling successfully, execute the application by running:

### ./build/app

Follow the on-screen prompts to perform arithmetic operations based on your input.

## Cleaning Up

To clean up (i.e., remove compiled object files and the executable), run:

### make clean

This will delete all .o files from bin/ and the app executable from build/.







