#include<iostream>
#include<fstream>
using namespace std;


class Polynom
{
public:
    int n; // ������� ��������
    double* k; //������������ �������� k[i]


    Polynom();
    Polynom(int an);
    Polynom(const Polynom&); 

    Polynom operator+(const Polynom&);   // �������� 
    Polynom operator-(const Polynom&);   // ���������
    Polynom operator*(const Polynom&);  //  ���������

    friend ostream& operator<<(ostream& s, const Polynom& c); // �������� ������
    friend istream& operator>>(istream& s, Polynom& c); // �������� �����
};

