// Lab_05.3.cpp
// <Грицай Адріан Васильович>
// Лабораторна робота № 5
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 14
#include <iostream>
#include <cmath>
using namespace std;

double t(double x);

int main() {
    double f_p, f_k;
    int n;
    cin >> f_p >> f_k >> n;

    double df = (f_k - f_p) / n;
    double f = f_p;

    while (f <= f_k + 1e-12) {
        double z = t(f * f) + 2 * t(2 * f + 1) + sqrt(t(1));
        cout << f << " " << z << endl;
        f += df;
    }
    return 0;
}

double t(double x) {
    if (abs(x) >= 1)
        return (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
    else {
        double S = 0;
        for (int j = 0; j <= 5; j++) {
            double a = pow(-1, j) * pow(x, 2 * j + 1) / tgamma(2 * j + 2);
            S += a;
        }
        return S;
    }
}
