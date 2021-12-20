#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int n, m, t, y;

    cout << "Введите степень полинома A <=40" << '\n';
    cin >> n;
    cout << "Введите степень полинома B <=40" << '\n';
    cin >> m;

    if (n <= 40 && m <= 40) {
        Polynom A(n);
        Polynom B(m), D, K, Y;


        cout << '\n' << "Введите коэфициенты полинома A:" << '(' << n + 1 << ')' << '\n';
        cin >> A;
        cout << '\n' << "А:" << A << '\n' << '\n';

        cout << "Введите коэфициенты полинома B:" << '(' << m + 1 << ')' << '\n';
        cin >> B;
        cout << "B:" << B << '\n' << '\n';



        cout << '\n' << "A+B:  " << (D = A + B) << '\n';
        cout << "A-B:  " << (K = A - B) << '\n' << '\n';
        cout << "A*B:  " << (Y = A * B) << '\n' << '\n';
    }
    else {
        cout << "НЕКОРРЕКТНЫЙ ВВОД СТЕПЕНИ ПОЛИНОМА" << '\n' << '\n' << '\n' << '\n';
        main();
    }

    system("pause");
}