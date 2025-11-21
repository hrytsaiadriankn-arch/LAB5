// Lab_05.5.cpp
// <Грицай Адріан Васильович>
// Лабораторна робота № 5
// Рекурсивні функції
// Варіант 14
#include <iostream>
using namespace std;

long long C(int n, int k) {
    if (k == 0 || k == n) return 1;
    return C(n - 1, k - 1) + C(n - 1, k);
}

long long F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return F(n - 1) + F(n - 2);
}

int main() {
    int n;
    cin >> n;

    long long s = 0;
    for (int k = 0; k <= n / 2; k++)
        s += C(n - k, k);

    cout << s << endl;
    cout << F(n) << endl;

    return 0;
}
