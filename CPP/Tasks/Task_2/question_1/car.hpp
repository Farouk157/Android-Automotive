#ifndef _CAR_HPP_
#define _CAR_HPP_

#include <string>
using namespace std;

class Car
{
    private:
        string company; 
        string model;
        int year;
    public:
    /*constructor*/
        Car();
    /*destructor*/
        ~Car();
    /* setter methods */
    void set_car_company(string com_name);
    void set_car_model(string car_model);
    void set_car_year(int car_year);
    /* getter methods */
    string get_car_company();
    string get_car_model();
    int get_car_year();    
};



#endif 