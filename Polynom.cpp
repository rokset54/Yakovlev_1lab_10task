#include "Polynom.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
Polynom::Polynom()
{
    k = NULL;
}
Polynom::Polynom(int an)
{
    int i;
    n = an;
    k = new double[n + 1];
    for (i = 0; i <= n; i++)
    {
        k[i] = 0;
    }
}

Polynom::Polynom(const Polynom& f)
{
    n = f.n;
    k = new double[n + 1];
    for (int i = 0; i <= n; i++)
        k[i] = f.k[i];
}

// А-В

Polynom Polynom::operator-(const Polynom& t)
{
    int i;
    if (n >= t.n)     //А>B
    {
        Polynom Z = *this;
        for (i = 0; i <= t.n; i++)
            Z.k[i] = k[i] - t.k[i];
        return Z;
    }
    else              //B>A
    {
        Polynom Z(t.n);
        for (i = 0; i <= n; i++)
            Z.k[i] = -t.k[i] + k[i];
        for (i = n + 1; i <= t.n; i++)
            Z.k[i] = -t.k[i];
        return Z;
    }
}
// A+B
Polynom Polynom::operator+(const Polynom& t)
{
    int i;
    if (n >= t.n)   //A>B
    {
        Polynom Z = *this;
        for (i = 0; i <= n; i++)
            Z.k[i] = k[i] + t.k[i];
        return Z;
    }
    else           //A<B
    {
        Polynom Z = t;
        for (i = 0; i <= n; i++)
            Z.k[i] = t.k[i] + k[i];
        return Z;
    }
}

// А*В
Polynom Polynom::operator*(const Polynom& t)
{
    int i, j, s = 0;
    Polynom Y(n + t.n);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= t.n; j++)
            Y.k[i + j] += k[i] * t.k[j];
    return Y;
}




ostream& operator << (ostream& s, const Polynom& c) // вывод
{
    int i, n = 0;
    for (i = 0; i <= c.n; i++)
    {
        if (c.k[i] != 0)
            n++;
    }
    if (n != 0)
    {
        if (c.k[0] != 0)
        {
            s << c.k[0];
        }
        for (i = 1; i <= c.n; i++)
        {
            if (c.k[i] < 0)
            {
                if (c.k[i] != -1)
                    s << c.k[i] << "X^" << i;
                else
                    s << "-" << "X^" << i;
            }
            else
            {
                if (c.k[i] != 0)
                {
                    if (c.k[i] != 1)
                        s << "+" << c.k[i] << "X^" << i;
                    else
                        s << "+" << "X^" << i;
                }
            }
        }
        s << '\n';
    }
    else
    {
        s << 0;
    }
    return s;
}

istream& operator>>(istream& s, Polynom& c) // ввод
{
    int i;
    for (i = 0; i <= c.n; i++)
    {
        s >> c.k[i];
    }
    return s;
}