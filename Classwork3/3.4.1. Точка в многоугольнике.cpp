#include <bits/stdc++.h>

using namespace std;


double angle(int x0, int y0, int x1, int y1) {
    return atan2(x0 * y1 - x1 * y0, x0 * x1 + y0 * y1);
}

int main() {
    int n, xa, ya;
    cin >> n >> xa >> ya;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        if (xa == points[i].first && ya == points[i].second){
            cout << "YES";
            return 0;
        }
    }
    points.push_back(points[0]);
    double s = 0;
    for (int i = 1; i <= n; ++i) {
        s += angle(points[i - 1].first - xa, points[i - 1].second - ya, points[i].first - xa, points[i].second - ya);

    }
    if (abs(abs(s) - 2 * M_PI) < 1e-6) cout << "YES";
    else cout << "NO";

    return 0;
}