#include <iostream>
#include <vector>


using namespace std;

class ParkingSystem {
private:
    vector<int> l; 
    vector<int> m; 
    vector<int> s;
    int l_n;
    int m_n;
    int s_n;

public:
    ParkingSystem(int big, int medium, int small) : l(big), m(medium), s(small){
        l_n = big;
        m_n = medium;
        s_n = small;
    }
    
    bool addCar(int carType){
        if( carType == 1 )
        {
            if(l_n > 0)
            {
                l.push_back(carType);
                l_n--;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(carType == 2)
        {
            if(m_n > 0)
            {
                m.push_back(carType);
                m_n--;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(carType == 3)
        {
            if(s_n > 0)
            {
                s.push_back(carType);
                s_n--;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return -1;
        }       
    }

};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
