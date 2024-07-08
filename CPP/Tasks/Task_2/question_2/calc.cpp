#include <iostream>
#include "clac.hpp"

using namespace std;

float Calculator:: addition(float n1, float n2)
{
    return n1 + n2;
}

float Calculator:: subtraction(float n1, float n2)
{
    return n1 - n2;
}

float Calculator:: multiply(float n1, float n2)
{
    return n1 * n2;
}

float Calculator:: division(float n1, float n2)
{
    if(n2 != 0)
    {
        if(n1 != 0)
        {
            return n1 / n2;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        cout << "Error can't divide by zero!!\n";
        return 0;
    }
}

float Calculator:: power(float n, int p)
{
    float res=1;
    while( p != 0)
    {
        res *= n;
        p--;
    }
    return res;
}

void Calculator:: performOperation()
{
    float num_1 , num_2;
    char operation;

    cout << "Enter first number: ";
    cin >> num_1;
    cout << "Enter second number: ";
    cin >> num_2;
    cout <<  "Enter operator (+, -, *, /, ^): ";
    cin >> operation;

    switch (operation)
    {
        case '+':
            cout << "Result = " << addition(num_1, num_2) << endl;
            break;
        case '-':
            cout << "Result = " << subtraction(num_1, num_2) << endl;
            break;
        case '*':
            cout << "Result = " << multiply(num_1, num_2) << endl;
            break;
        case '/':
            cout << "Result = " << division(num_1, num_2) << endl;
            break;
        case '^':
            cout << "Result = " << power(num_1, num_2) << endl;
            break;
        default:
            cerr << "Invalid operator!" << endl;
    }  
}