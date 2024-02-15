#include <bits/stdc++.h>


using namespace std;


int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double y = x1 * y2 - x2 * y1;
    double x = x1 * x2 + y1 * y2;
    cout << setprecision(12) << abs(atan2(y, x));
};