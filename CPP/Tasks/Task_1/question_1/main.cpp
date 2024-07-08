#include <iostream>


using namespace std;

int main (void)
{
    int number{0};
    int result{0};

    cout << "Please enter number: ";
    cin >> number;
    
    while(number)
    {
        result += number;
        cout << "Please enter number again: ";
        cin >> number;
    }

    cout << "result = " << result << endl; 

    return 0;
}