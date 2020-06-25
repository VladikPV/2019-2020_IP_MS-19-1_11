#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
double f_5(double put_x)
{
	double y = 0, i = 1;
	/*y = 1 / put_x + 1 / (3 * pow(put_x, 3)) + 1 / (5 * pow(put_x, 5)) + 1 / (7 * pow(put_x, 7)) + 1 / (9 * pow(put_x, 9)) + 1 / (11 * pow(put_x, 11));*/
	while (i != 7)
	{
		y += (pow((put_x - 2.0),i)/i)*(pow(-1,i)/pow(3,(i + 1)) - 1);
		i++;
	}
	return y;
}
double f(double put_x, double put_E, int &n)
{
	double y = 0;
	while (put_E != 200)
	{
		y += (pow((put_x - 2.0), n) / n) * (pow(-1, n - 1) / pow(3, (n)) - 1);
		n++;
		put_E++;
	}
	y = log(3) + y;
	return y;
}
void put_t2(double &pr_E)
{
	while (pr_E <= 0)
	{
		while (pr_E == 0)
		{
			cout << " Введите число, соотвецтвующее области допустимых значений! Не ноль!\n Введите E, где Е > 0:\n";
			cin >> pr_E;
		}
		while (pr_E < 0)
		{
			cout << " Введите число, соотвецтвующее области допустимых значений! Не отрицательное!\n Введите E, где Е > 0:\n";
			cin >> pr_E;
		}
	}
}
void put_t1(double &pr_x)
{
	while (pr_x < -1 || pr_x > 3)
	{
		cout << " Введите число, соотвецтвующее области допустимых значений!\n Введите число x, где -1 <= х <= 3:\n";
		cin >> pr_x;
	}
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << log(2.71);
	double x, E; int n_keep = 1;
	cout << "  Задание 2\n";
	cout << " Введите число x, где -1 <= х <= 3::" << endl;
	cin >> x;
	put_t1(x);  // проверка правильности ввода
	cout << " Введите нужную точность исчисления суммы ряда E, где Е > 0:" << endl;
	cin >> E;
	put_t2(E);  // проверка правильности ввода
	cout << " Тогда можно рассмотреть ln(2*x - x^2 + 3). Результаты исчисления:\n";
	cout << "____________________________________________________________________\n";
	cout << " Сумма первых пяти элементов ряда составляет:\n";
	cout << "  S = " << f_5(x) << '\n';
	cout << " Сумма ряда с точностью " << E << " составляет:\n";
	cout << "  S = " << f(x, E, n_keep) << '\n';
	cout << "  Количество выполненых итераций: " << n_keep << endl;
	cout << " Результаты исчислений с помощью стандартных функций:\n";
	cout << "  log(" << 2*x - pow(x, 2) + 3 << ") = "<< log(2 * x - pow(x, 2) + 3) << '\n';
	system("pause");
	return 0;
}