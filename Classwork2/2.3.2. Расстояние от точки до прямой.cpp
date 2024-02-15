#include <bits/stdc++.h>

using namespace std;

int main() {
    double x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    double d = abs(a * x + b * y + c) / sqrt(a * a + b * b);
    cout << setprecision(10) << d;
};