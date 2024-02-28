#include <bits/stdc++.h>

using namespace std;

signed main() {
    long double a, b, c, x0, y0;
    cin >> a >> b >> c >> x0 >> y0;
    long double k = - (a * x0 + b * y0 + c) / (a * a + b * b);
    cout << setprecision(12) << x0 + 2 * k * a << " " << y0 + 2 * k * b;
}

