#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

using namespace std;

/*
Implement a class for a dynamic array (Vector)
    * Containing the following functions
        * resize() - resize the array to double the size
        * pushback(value) - add the value to the end of the array
        * popback() - remove the last element from the array
        * removeAt(index) - remove the element at the given index
        * insertAt(index, value) - insert the value at the given index and shift the elements to the right
        * insertMiddle(value) - insert the value in the middle of the array
        * removeMiddle() - remove the middle element from the array
        * size() - return the size of the array
        * print() - print the array
 
    * The following overload constructors:
        * DynamicArray() - default constructor with capacity of 1
        * DynamicArray(size) - constructor with given capacity
        * DynamicArray(size, value) - constructor with given capacity and initial value for all elements --> DynamicArray arr(5, 10);
        * DynamicArray(size, values) - constructor with given capacity and initial values --> DynamicArray arr(5, new int[5]{1, 2, 3, 4, 5});
        * DynamicArray(arr) - copy constructor
 
    * Appropriate destructor
 
    - Private members:
        * array - pointer to the array
        * capacity - capacity of the array
        * currentSize - current size of the array
*/
class Vector
{
    private: 
        int current_size;
        int capacity;
        int *array;

        /*private to resize and double the vector size*/
        void resize(void);

    public:
        /*constructors*/
        Vector();
        Vector(const int &size);
        Vector(const int &size, const int &value);
        Vector(const int &size, const int *values);
        Vector(const Vector &obj);
        /*destructor*/
        ~Vector();

        /*apis for interface with the vector container*/
        void pushback(const int &num);
        void popback();
        void removeAt(int index);
        void insertAt(int index,const int &value);
        void insertMiddle(const int &value);
        void removeMiddle();
        int  size();
        void print();
};






#endif
