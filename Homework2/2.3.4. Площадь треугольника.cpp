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


struct Vector {
    long double x;
    long double y;

    Vector(const Point &a, const Point &b) {
        x = b.x - a.x;
        y = b.y - a.y;
    };
};

long double operator*(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}

long double operator&(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}


signed main() {
    Point a, b, c;
    cin >> a >> b >> c;
    cout << 0.5 * abs(Vector(a, b) & Vector(a, c));
}

