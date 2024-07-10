# Linux administration task 2

## Question 1: Using VI editor only!!!! 

1. Implement the binary search algorithm inside the binary_search function.

Ensure that it returns the index of the searched element or -1 if the element is not present.

2. In the main function, declare an array and an element to search.

Call the binary search function with appropriate arguments.

3. Make sure to print the output of the search using printf()

4. Compile and run your program to verify the correctness of your binary search implementation.


solution: 

![Screenshot from 2024-07-10 16-16-04](https://github.com/Farouk157/Android-Automotive/assets/96669463/c484f4d3-2b9e-4be0-a763-b4a0a1b4536b)


![2](https://github.com/Farouk157/Android-Automotive/assets/96669463/332566f7-5245-4aea-9321-db1869062ff1)

![3](https://github.com/Farouk157/Android-Automotive/assets/96669463/e67cf9e4-209c-458f-9782-7c1da9843309)

![Screenshot from 2024-07-10 15-56-58](https://github.com/Farouk157/Android-Automotive/assets/96669463/144acf1a-3626-4192-ae20-b611b21bc70a)



## Question 2: 

Move the binary file output to the directory /usr/local/bin with sudo permissions.

Afterward, attempt to execute the binary from any working directory and explain the outcome.

Provide a detailed explanation supported by evidence as to why the

binary can be executed from any location.


solution: 

1. here is the problem trying to run bsearch from any directory but not found 


![Screenshot from 2024-07-10 16-30-00](https://github.com/Farouk157/Android-Automotive/assets/96669463/fdc024ff-aa88-492c-870f-baa49ee8eb92)

2. this error appeared cause the shell didn't find this bsearch as binary file in any of the PATH variable directories

3. here is the paths of directories that will be searched 

![Screenshot from 2024-07-10 16-32-59](https://github.com/Farouk157/Android-Automotive/assets/96669463/5eebdb23-0c13-4bbb-8f27-4abd22916d8b)

4. adding the binary file bsearch in /usr/local/bin to be able to run this file as command from any where


![Screenshot from 2024-07-10 16-08-33](https://github.com/Farouk157/Android-Automotive/assets/96669463/be11cdc5-e16f-4449-8ec7-ce0e80c22995)



## Question 3: Na2na2a 

1. List the available shells in your system.

![Screenshot from 2024-07-10 16-40-03](https://github.com/Farouk157/Android-Automotive/assets/96669463/5c18181e-5d58-4385-be9b-a1c7079fac40)


2. List the environment variables in your current shell.

![Screenshot from 2024-07-10 16-41-32](https://github.com/Farouk157/Android-Automotive/assets/96669463/8cc47095-15e5-49bf-94fa-71e6c04ade31)


3. Display your current shell name.

![Screenshot from 2024-07-10 16-43-36](https://github.com/Farouk157/Android-Automotive/assets/96669463/332d6411-092c-4d64-aea4-fba204e89935)


4. Execute the following command :

echo \ then press enter

What is the purpose of \ ?

![Screenshot from 2024-07-10 16-47-08](https://github.com/Farouk157/Android-Automotive/assets/96669463/125c2cdd-cda1-4463-b172-dc088103d9e4)

the backslash ( \ ) character serves as an escape character.

The backslash ( \ ) escapes the following character, which in this case is a newline character (pressing Enter).

This means that echo will interpret \ and the newline as separate parts of the command, 

rather than ending the echo command prematurely.

so, when we execute echo \ , the output you will see is simply a newline in the terminal.

The \ itself is not printed because it is escaped, and echo just outputs a newline.


5. Create a Bash shell alias named PrintPath for the “echo $PATH” command

 
![Screenshot from 2024-07-10 16-54-32](https://github.com/Farouk157/Android-Automotive/assets/96669463/74fdf2a6-ea42-46c1-b44b-72bcfde51a28)

![Screenshot from 2024-07-10 17-00-00](https://github.com/Farouk157/Android-Automotive/assets/96669463/2b2e419e-6227-4829-97ff-1705f03c4f93)

![Screenshot from 2024-07-10 16-59-41](https://github.com/Farouk157/Android-Automotive/assets/96669463/f721f66b-8d3d-4523-afde-29215557b95a)


