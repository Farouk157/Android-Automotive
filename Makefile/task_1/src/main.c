#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "multi.h"
#include "div.h"

int main() {
    float num1, num2, result;
    char op;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch(op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = sub(num1, num2);
            break;
        case '*':
            result = multi(num1, num2);
            break;
        case '/':
            result = division(num1, num2);
            break;
        default:
            printf("Error! Operator is not correct");
            return -1;
    }

    printf("%.3f %c %.3f = %.3f\n", num1, op, num2, result);

    return 0;
}