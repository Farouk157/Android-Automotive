#include <iostream>
#include <string>
#include "car.hpp"

using namespace std;

int main()
{
    Car _1st_car;

    string comp, mod;
    int yea;

    cout <<"Please enter the car company: ";
    cin >> comp;
    cout <<"Please enter the car model: ";
    cin >> mod;
    cout <<"Please enter the car year: ";
    cin >> yea;

    _1st_car.set_car_company(comp);
    _1st_car.set_car_model(mod);
    _1st_car.set_car_year(yea);

    cout << "******************************************\n";
    cout <<"Your car details:\n"
         <<"1- Car company: "<< _1st_car.get_car_company()<<"\n"
         <<"2- Car model: "<< _1st_car.get_car_model()<<"\n"
         <<"3- Car year: "<< _1st_car.get_car_year()<< "\n";
    
    cout << "******************************************\n";



    return 0;
}



