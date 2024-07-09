#include <iostream>
#include "vector.hpp"

using namespace std;


Vector:: Vector() : capacity(1), current_size(0)
{
    array = new int[capacity];
}

Vector:: Vector(const int &size) : capacity(size), current_size(0)
{
    array = new int[capacity];
}

Vector:: Vector(const int &size, const int &value) : capacity(size), current_size(size)
{
    array = new int[capacity];
    for(int i = 0; i < current_size; i++)
    {
        array[i] = value;
    }
}

Vector:: Vector(const int &size, const int *values) : capacity(size), current_size(size)
{
    array = new int[capacity];
    for(int i = 0; i < current_size; i++)
    {
        array[i] = values[i];
    }
}

Vector:: Vector(const Vector &obj) : capacity(obj.capacity), current_size(obj.current_size)
{
    array = new int[capacity];
    for(int i = 0; i < current_size; i++)
    {
        array[i] = obj.array[i];
    }
}

Vector:: ~Vector()
{
    delete[] array;
}

void Vector:: resize(void)
{
    int temp_capacity = capacity * 2;
    int *temp_array = new int[temp_capacity];
    for(int i = 0; i < capacity; i++)
    {
        temp_array[i] = array[i];
    }

    delete[] array;

    capacity = temp_capacity;
    array = temp_array;
}

void Vector:: pushback(const int &num)
{
    if(current_size >= capacity)
    {
        resize();
    }
    array[current_size++] = num;
}

void  Vector:: popback()
{
    if (current_size > 0){
        --current_size;
    }
}

void Vector:: removeAt(int index)
{
    if (index >= 0 && index < current_size) {
        for (int i = (index-1); i < current_size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --current_size;
    }

}

void Vector:: insertAt(int index,const int &value)
{
    if (index >= 0 && index <= current_size) {
        if (current_size >= capacity) {
            resize();
        }

        for (int i = current_size; i > index-1; --i) {
            array[i] = array[i - 1];
        }
        index--;
        array[index] = value;
        ++current_size;
    }
}

void Vector:: insertMiddle(const int &value)
{
    insertAt(current_size / 2, value);
}

void Vector:: removeMiddle()
{
    removeAt(current_size/2);
}

int  Vector:: size()
{
    return current_size;
}

void Vector:: print()
{
    for(int i=0; i < current_size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}