// Lab_05.2.cpp
// <Грицай Адріан Васильович>
// Лабораторна робота № 5
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 14
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main() {
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cin >> xp >> xk >> dx >> eps;

    cout << fixed;
    cout << "------------------------------------------------------------\n";
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "cos(x)" << " |"
        << setw(12) << "S" << " |"
        << setw(7) << "n" << " |\n";
    cout << "------------------------------------------------------------\n";

    x = xp;
    while (x <= xk) {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(6) << cos(x) << " |"
            << setw(12) << setprecision(6) << s << " |"
            << setw(7) << n << " |\n";
        x += dx;
    }

    cout << "------------------------------------------------------------\n";
    return 0;
}

void S(const double x, const double eps, int& n, double& s) {
    n = 0;
    double a = 1;
    s = a;

    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a) {
    double R = -x * x / ((2 * n) * (2 * n - 1));
    a *= R;
}