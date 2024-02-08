#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long ans = 1;
    int deg = n;
    while (deg) {
        if (deg % 2 == 1) {
            ans = (ans * n) % m;
            deg--;
        } else {
            n = (n * n) % m;
            deg /= 2;
        }
    }


    cout << ans << "\n";
}