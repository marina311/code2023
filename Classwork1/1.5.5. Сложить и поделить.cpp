#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long mod(long long x, int MOD) {
    return (x % MOD + MOD) % MOD;
}

int inv(int a, int MOD) {
    int x, y;
    gcd(a, MOD, x, y);
    return mod(x, MOD);
}


int main() {
    long long a, b, c, d;
    int MOD = 1000000007;
    cin >> a >> b >> c >> d;
    a = (mod(a * d, MOD) + mod(b * c, MOD)) % MOD;
    b = mod(b * d, MOD);
    long long res = mod(a * inv(b, MOD), MOD);
    cout << res;
    return 0;
}