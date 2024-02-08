#include <bits/stdc++.h>

using namespace std;

// Фу́нкция Э́йлера phi (n) — мультипликативная арифметическая функция,
// значение которой равно количеству натуральных чисел, меньших либо равных
//n и взаимно простых с ним
int main() {
    long long n;
    while (cin >> n) {
        long long k = 2, phi = n;
        while (k * k <= n) {
            if (n % k == 0)
                phi = phi - phi / k;
            while (n % k == 0)
                n /= k;
            k += 1;
        }
        if (n > 1)
            phi = phi - phi / n;
        cout << phi << endl;
    }
    return 0;
}