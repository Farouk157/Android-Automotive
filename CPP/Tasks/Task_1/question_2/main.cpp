#include <iostream>

using namespace std;

int main(void)
{
    int number{0};
    int hour{0},min{0},sec{0};

    cout << "Please Enter the number: ";
    cin >> number;

    while(number > 60)
    {
        if(number > 3600)
        {
            hour = number/3600;
            number -= (hour * 3600); 
        }
        else
        {
            min = number / 60;
            number -= (min * 60); 
        }
    }
    
    sec = number;

    cout <<"H:M:S = " << hour << " : "<< min << " : " << sec <<endl;
    

    return 0;
}