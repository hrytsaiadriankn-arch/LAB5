// Lab_05.1.cpp
// <Грицай Адріан Васильович>
// Лабораторна робота № 5
// Функції, що містять арифметичний вираз
// Варіант 14
#include <iostream>
#include <cmath>
using namespace std;

double h(double a, double b) {
    return a * a * sin(b) + b * b * cos(a);
}

int main() {
    double s, t;
    cin >> s >> t;

    double numerator = pow(h(t * t, 1), 3) + h(1, t * s * s);
    double denominator = 1 + pow(h(s, t), 2);
    double result = numerator / denominator;

    cout << result;
    return 0;
}