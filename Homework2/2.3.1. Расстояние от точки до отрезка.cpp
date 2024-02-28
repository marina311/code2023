#include <bits/stdc++.h>

using namespace std;

struct Point {
    long double x, y;

    Point(long double x = 0, long double y = 0) : x(x), y(y) {};
};


istream &operator>>(istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

long double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

signed main() {
    Point a, b, c;
    cin >> a >> b >> c;
    if (b.x == c.x && b.y == c.y) {
        cout << setprecision(15) << fixed << dist(a, b);
        return 0;
    }
    Point d(b.x + b.y - c.y, b.y + c.x - b.x);
    Point e(c.x + b.y - c.y, c.y + c.x - b.x);
    auto s1 = (b.x - d.x) * (a.y - d.y) - (b.y - d.y) * (a.x - d.x);
    auto s2 = (c.x - e.x) * (a.y - e.y) - (c.y - e.y) * (a.x - e.x);
    if (s1 <= 0 && s2 >= 0 || s1 >= 0 && s2 <= 0) {
        cout << setprecision(15) << fixed << abs(((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x))) / dist(b, c);
    } else cout << setprecision(15) << fixed << abs(min(dist(a, b), dist(a, c)));
}
