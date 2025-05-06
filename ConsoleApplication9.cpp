#include <iostream>

//Написать перегруженную функцию вычитания. Можете написать перегрузки своих функций

int Difference(int a, int b)
{
    return a - b;
}

int Difference(int a, int b, int c)
{
    return a - b - c;
}

double Difference(double a, double b)
{
    return a - b;
}

void myFunc(int a)
{
    std::cout << "Это вызов функции myFunc, а число переданное как параметр является Integer.\n";
}

void myFunc(double a)
{
    std::cout << "Это вызов функции myFunc, а число переданное как параметр является Double.\n";
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::cout << Difference(4, 3) << std::endl;
    std::cout << Difference(5.7, 4.3) << std::endl;
    std::cout << Difference(9, 23, -18) << std::endl;
    myFunc(9);
    myFunc(6.7);
}