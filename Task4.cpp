#include "stdio.h"
#include <locale>
#include <iostream>
#include <cstdlib>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "Russian");
    while(1)
    {
        int z=0;
        cout<<"Введите действие 1 расчет , 0 выыход: ";
        cin>>z;
        if(z!=1)
            break;

	    cout << "Вычисление значений функций log(x+(sqrt((x*x)+1)))\n\n";
	    double x; // Значение аргумента
	    double func; // Точное значение функции
	    double sum; // Значение частичной суммы
	    int n; // Число слогаемых в частичной сумме

	    cout << "Задание 1" <<'\n';
	    cout << "Введите значение аргумент > ";
	    cin >> x;
	    cout << "Задайте число слогаемых > ";
	    cin >> n;
	    func = log(x+(sqrt((x*x)+1)));// Вычисление "точного" значения
	    double last;
	    sum = sumN(x, n, last);
	    cout << "Точное значение функции равно " << func <<'\n';
	    cout << "Частичная сумма ряда равна " << sum <<'\n';
	    cout << "Абсолютная погрешность равна " << fabs(func - sum) <<'\n';
	    cout << "Последнее слогаемое равно " << last <<'\n';

	    cout << "\n Задание 2" <<'\n';
	    double E;
	    cout << "Введите значение аргумента > ";
	    cin >> x;
	    cout << "Задайте точность вычислений > ";
	    cin >> E;
	    func = log(x+(sqrt((x*x)+1)));// Вычисление "точного" значения
	    sum = sumE(x, E, n);
	    cout << "Точное значение функции равно " << func <<'\n';
	    cout << "Частичная сумма ряда с заданной точностью равна " << sum <<'\n';
	    cout << "Учтено " << n << " членов ряда " <<'\n';
	    sum = sumE(x, E / 10, n);
	    cout << "Частичная сумма ряда с точностью, большей в 10 раз, равна " << sum <<'\n';
	    cout << "Учтено " << n << " членов ряда " <<'\n';
	    
    }
    system("pause");
    return 0;
}

double sumN(double x, int n, double &last)
{
	// Инициализация переменной last
	last = x;
	double sum = last;
	for (int i = 1; i < n; ++i)
	{
		double r; 
		r = -(i*2-1)*x*x*(i*2-1)/(2*i+1)/(i*2); // Вычисление значения r
		last *= r;
		sum += last;
	}
	return sum;
}

double sumE(double x, double E, int &n)
{
	double last;
	// Инициализация переменной last
	last = x;
	double sum = last;
	for (n = 1; fabs(last) > E ; ++n)
	{
		double r; 
		r = -(n*2-1)*x*x*(n*2-1)/(n*2+1)/(n*2); // Вычисление значения r
		last *= r;
		sum += last;
	}
	return sum;
}
