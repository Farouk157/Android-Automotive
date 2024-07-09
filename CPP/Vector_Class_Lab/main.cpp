#include <iostream>
#include "vector.hpp"

using namespace std;

int main()
{
    Vector arr1;  // default constructor
    arr1.pushback(1);
    arr1.pushback(2);
    arr1.pushback(3);
    arr1.pushback(4);
    arr1.pushback(5);
    arr1.print();  // 1 2 3 4 5


    arr1.popback();
    arr1.print();  // 1 2 3 4 

    Vector arr2(5, 10);  // size and value constructor
    arr2.print();       // 10 10 10 10 10

    int values[] = {10, 20, 30, 40, 50};
    
    Vector arr3(5, values);  // size and array constructor
    arr3.print();  // [1, 2, 3, 4, 5]

    Vector arr4(arr3);  // copy constructor
    arr4.print();  // 1 2 3 4 5

    arr1.insertAt(3, 15);
    arr1.print();

    arr3.removeAt(2);
    arr3.print();

    

}