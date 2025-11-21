// Lab_05.4.cpp
// <Грицай Адріан Васильович>
// Лабораторна робота № 5
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 14
#include <iostream>
#include <cmath>
using namespace std;

double term(int i) {
    return (i + 1.0 / (i * i)) / pow(1 + exp(1.0 / i), 1.0 / 2);
}

double P0(int N) {
    double p = 1;
    for (int i = N; i <= 10; i++)
        p *= term(i);
    return p;
}

double P1(int N, int i) {
    if (i > 10) return 1;
    return term(i) * P1(N, i + 1);
}

double P2(int N, int i) {
    if (i < N) return 1;
    return term(i) * P2(N, i - 1);
}

double P3(int N, int i, double t) {
    t *= term(i);
    if (i >= 10) return t;
    return P3(N, i + 1, t);
}

double P4(int N, int i, double t) {
    t *= term(i);
    if (i <= N) return t;
    return P4(N, i - 1, t);
}

int main() {
    int N;
    cin >> N;
    cout << P0(N) << endl;
    cout << P1(N, N) << endl;
    cout << P2(N, 10) << endl;
    cout << P3(N, N, 1) << endl;
    cout << P4(N, 10, 1) << endl;
    return 0;
}
