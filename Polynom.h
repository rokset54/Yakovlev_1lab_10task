#include<iostream>
#include<fstream>
using namespace std;


class Polynom
{
public:
    int n; // степень полинома
    double* k; //коэффициенты полинома k[i]


    Polynom();
    Polynom(int an);
    Polynom(const Polynom&); 

    Polynom operator+(const Polynom&);   // сложение 
    Polynom operator-(const Polynom&);   // вычитание
    Polynom operator*(const Polynom&);  //  умножение

    friend ostream& operator<<(ostream& s, const Polynom& c); // оператор вывода
    friend istream& operator>>(istream& s, Polynom& c); // оператор ввода
};

