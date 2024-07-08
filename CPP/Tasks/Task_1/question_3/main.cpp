#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string decimalToBinary(int decimal);
int binaryToDecimal(string binary);

int main (void)
{
    string binary;
    int decimal{0} , option{0};

    cout <<"1- convert decimal to binary\n"<<"2- convert binary to decimal\n"<<"Please choose option: ";
    cin >> option;
    

    switch(option)
    {
        case 1:
            cout << "Please enter the decimal number: ";
            cin >> decimal;
            binary = decimalToBinary(decimal);
            cout << "Binary equivalent: " << binary << endl;
            break;
        case 2:
            cout << "Please enter the binary number: ";
            cin >> binary;
            decimal = binaryToDecimal(binary);
            cout << "Decimal equivalent: " << decimal << endl;
            break;
        default:
            cout << "invalid option\n";
            break;
    }
    return 0;
}


string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    string binary = "";
    while (decimal > 0) {
        binary += to_string(decimal % 2);
        decimal /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;

    // Iterate over the binary string from right to left
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}
