#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x)
{
    double y;
    if (5 < x && x < 10)
    {
        y = exp((-2 + x) / 5) * pow(pow(x, 2) + pow(x, 4) + log(abs(x - 3.14)), -0.5);
    }
    else if (-3 < x && x <= 2)
    {
        y = pow(x, -25);
    }
    else
    {
        y = pow(x, 30);
    }
    return y;
}


int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double a, b, h;
    cout << "  Задание_1, вариант 11" << endl;
        if (argc != 4)
        {
            cout << " Введите отрезок [a; b]: " << endl;
            do
            {
                cout << " Введите число a: "; cin >> a;
                cout << " Введите число b: "; cin >> b;
                if (b < a) cout << "  Внимание! b < a - неправильное выражение! Задайте a, b ещё раз (где a < b)" << endl;
            } while (b < a);
            do {
                cout << " Задайте длину шага h: ";
                cin >> h;
                if (h == 0 && a != b)cout << "  Внимание! h = 0 и a != b. Задайте h != 0 или h = 0 при a = b" << endl;
            } while (h == 0 && a != b);
        }
        else
        {
            a = atof(argv[1]); b = atof(argv[2]); h = atof(argv[3]);
            cout << " Заданый отрезок [a; b]: [" << a << "; " << b << "]" << endl;
            cout << " Заданая длина шага h: " << h << endl;
            while (b < a)
            {
                cout << "  Внимание! b < a - неправильное выражение! Задайте a, b ещё раз (где a < b)" << endl;
                cout << " Введите число a: "; cin >> a;
                cout << " Введите число b: "; cin >> b;
            }
            while (h == 0 && a != b)
            {
                cout << "  Внимание! h = 0 и a != b. Задайте h != 0 или h = 0 при a = b" << endl;
                cout << " Задайте длину шага h: ";
                cin >> h;
            }
        }
            cout << " X\t\t\tY\n";
            cout << "-----------------------------------------" << endl;
            if (h == 0 && a == b)
            {
                cout << " " << fixed << setprecision(3) << b << "\r\t\t\t" << scientific << f(b) << endl;
            }
            if (h > 0)
            {
                cout << " " << fixed << setprecision (3) << a << "\r\t\t\t" << scientific << f(a) << endl;
                while ((a + h) <= b)
                {
                    cout << " " << fixed << setprecision(3) << (a + h) << "\r\t\t\t";
                    cout << scientific << f(a + h) << endl;
                    a += h;
                }
            }
            if (h < 0)
            {
                cout << " " << fixed << setprecision(3) << b << "\r\t\t\t" << scientific << f(b) << endl;
                while (b + h >= a)
                {
                    cout << " " << fixed << setprecision(3) << (b + h) << "\r\t\t\t";
                    cout << scientific << f(b + h) << endl;
                    b += h;
                }
            }
    system("pause");
    return 0;
}