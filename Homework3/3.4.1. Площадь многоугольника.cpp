#include <bits/stdc++.h>

using namespace std;


double angle(int x0, int y0, int x1, int y1) {
    return atan2(x0 * y1 - x1 * y0, x0 * x1 + y0 * y1);
}

double square(int x0, int y0, int x1, int y1) {
    return 0.5 * (x0 * y1 - x1 * y0);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    int x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1;
    double s = 0;
    for (int i = 0; i < n - 2; ++i) {
        cin >> x2 >> y2;
        s += square(x1 - x0, y1 - y0, x2 - x0, y2 - y0);
        x1 = x2;
        y1 = y2;

    }
    cout << setprecision(12) << abs(s);

    return 0;
}