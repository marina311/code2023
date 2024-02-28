#include <bits/stdc++.h>

using namespace std;


signed main() {
    long double a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a2 == 0) {
        swap(a1, a2);
        swap(b1, b2);
        swap(c1, c2);
    }
    if (a1 != 0) {
        b1 = b1 / a1 * a2 - b2;
        c1 = c1 / a1 * a2 - c2;
    }
    long double y = -c1 / b1;
    long double x = (-c2 - b2 * y) / a2;


    cout << x << " " << y;
}

