#include <bits/stdc++.h>

using namespace std;


int main() {
    long long n, k = 2;
    cin >> n;
    while (k * k <= n) {
        while (n % k == 0) {
            cout << k << " ";
            n /= k;
        }
        k += 1;
    }
    if (n > 1) cout << n << "\n";
    return 0;
}