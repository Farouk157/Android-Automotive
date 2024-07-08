#ifndef _CALC_HPP_
#define _CALC_HPP_


class Calculator
{
    private:
        float addition(float n1, float n2);
        float subtraction(float n1, float n2);
        float multiply(float n1, float n2);
        float division(float n1, float n2);
        float power(float n, int p);

    public:
        void performOperation();
};


#endif
