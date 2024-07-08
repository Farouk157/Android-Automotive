#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    string first_name;
    string second_name;
    string third_name;
} Name_t;

typedef struct
{
    string month;
    int day;
    int year;
} Date_t;

typedef struct
{
    string street;
    string city;
    string country;
} Address_t;

typedef struct
{
    string tele_number;
    string phone_num;
    string e_mail;
} Contacts_t;

typedef struct
{
    int basic;
    int addtional;
    int deduction;
    int taxes;
} Salary_t;

typedef struct
{
    Name_t *name;
    Date_t *date;
    Address_t *address;
    Contacts_t *contact;
    Salary_t *salary;
    string job;
} Employee_info_t;

int main(void)
{
    Employee_info_t _1st_employee;


    _1st_employee.name = new Name_t();
    _1st_employee.date = new Date_t();
    _1st_employee.address = new Address_t();
    _1st_employee.contact = new Contacts_t();
    _1st_employee.salary = new Salary_t();


    _1st_employee.name->first_name = "Farouk";
    _1st_employee.name->second_name = "Ehab";
    _1st_employee.name->third_name = "Fouad";
    _1st_employee.date->day = 1;
    _1st_employee.date->month = "October";
    _1st_employee.date->year = 1999;
    _1st_employee.address->street = "Salah_abdelzaher_st";
    _1st_employee.address->city = "Giza";
    _1st_employee.address->country = "Egypt";
    _1st_employee.contact->tele_number = "0238600295";
    _1st_employee.contact->phone_num = "01068555223";
    _1st_employee.contact->e_mail = "faroukehap90@gmail.com";
    _1st_employee.salary->basic = 10000;
    _1st_employee.salary->addtional = 5000;
    _1st_employee.salary->deduction = 500;
    _1st_employee.salary->taxes = 1000;
    _1st_employee.job = "Android_Automotive_Engineer";

    cout << "Employee name: " << _1st_employee.name->first_name << " " << _1st_employee.name->second_name << " "
        << _1st_employee.name->third_name << "\n";

    cout << "Employee date of birth: " << _1st_employee.date->day
        << " " <<_1st_employee.date->month<<" " <<_1st_employee.date->year <<"\n";

    cout << "Employee Address: " << _1st_employee.address->street<<","<< _1st_employee.address->city
        <<","<< _1st_employee.address->country << "\n";
    
    cout << "Employee contacts\n" << "1- Home number: " << _1st_employee.contact->tele_number
        <<"\n2- Phone number: " << _1st_employee.contact->phone_num << "\n3- e-mail: " 
        << _1st_employee.contact->e_mail << "\n";

    cout << "Employee Job: " <<  _1st_employee.job << "\n";  


    delete _1st_employee.name;
    delete _1st_employee.date;
    delete _1st_employee.address;
    delete _1st_employee.contact;
    delete _1st_employee.salary;

        return 0;
}