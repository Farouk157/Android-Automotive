#include <iostream>
#include <string>
#include "car.hpp"

using namespace std;


/*constructor*/
Car:: Car()
{

}
/*destructor*/
Car:: ~Car()
{
    cout << "obeject destroyed\n";
}
/* setter methods */
void Car:: set_car_company(string com_name)
{
    company = com_name;
}
void Car:: set_car_model(string car_model)
{
    model = car_model;
}
void Car:: set_car_year(int car_year)
{
    year = car_year;
}
/* getter methods */
string Car:: get_car_company()
{
    return company;
}
string Car:: get_car_model()
{
    return model;
}
int Car:: get_car_year()
{
    return year;
}