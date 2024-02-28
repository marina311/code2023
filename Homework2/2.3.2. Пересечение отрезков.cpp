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

long double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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

double angle(const Vector &a, const Vector &b) {
    return atan2(a & b, a * b);
}

bool orientation(const Point &a, const Point &b, const Point c) {
    return (Vector(a, b) & Vector(a, c)) >= 0;
}

bool point_in_segment(const Point x0, const Point a, const Point b) {
    if ((Vector(x0, a) & Vector(x0, b)) != 0) return false;
    if ((Vector(x0, a) * Vector(x0, b)) <= 0) return true;
    return false;

}

bool segments_intersection(const Point a, const Point b, const Point c, const Point d) {
    if (point_in_segment(a, c, d) || point_in_segment(b, c, d) ||
        point_in_segment(c, a, b) || point_in_segment(d, a, b)) // одна из точек
        return true;
    if ((Vector(a, b) & Vector(c, d)) == 0) return false;
    return orientation(a, c, b) == orientation(a, b, d) && orientation(c, b, d) == orientation(c, d, a);
}


signed main() {
    Point a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (segments_intersection(a, b, c, d) ? "YES" : "NO");
}

