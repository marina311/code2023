#include <bits/stdc++.h>

using namespace std;

struct Point {
    long double x;
    long double y;

    Point(long double x = 0, long double y = 0) : x(x), y(y) {};

};

bool comp(const Point &a, const Point &b) {
    return a.x < a.y || (a.x == a.y && b.x < b.y);
}

struct Vector {
    long double x;
    long double y;

    Vector(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    };
};

bool operator<(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator==(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

long double operator*(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

long double operator^(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

bool segment(Point x0, Point a, Point b) {
    if ((Vector(x0, a) ^ Vector(x0, b)) != 0) return false;
    if ((Vector(x0, a) * Vector(x0, b)) <= 0) return true;
    return false;

}

double angle(Vector a, Vector b) {
    return atan2(a ^ b, a * b);
}

bool orient(Point a, Point b, Point c) {
    return (Vector(a, b) ^ Vector(a, c)) >= 0;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    Point start = points[0];
    vector<pair<double, Point>> angles;
    for (int i = 1; i < n; ++i) {
        angles.push_back({angle(Vector(1, 0), Vector(points[i], start)), points[i]});
    }
    sort(angles.begin(), angles.end());

    int k;
    cin >> k;
    while (k--) {
        Point x0;
        cin >> x0.x >> x0.y;
        if (segment(x0, angles[0].second, start) || segment(x0, angles[n - 2].second, start)) {
            cout << "BORDER\n";
            continue;
        }

        if (!orient(start, angles[0].second, x0) || orient(start, angles[n - 2].second, x0)) {
            cout << "OUTSIDE\n";
            continue;
        }
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            Point a = angles[mid].second;

            if (orient(start, a, x0) )
                left = mid;
            else
                right = mid;

        }
        Point a = angles[left].second;
        Point b = angles[left + 1].second;
        if (!orient(a, b, x0)) {
            cout << "OUTSIDE\n";
            continue;
        }
        if (segment(x0, a, b))
            cout << "BORDER\n";
        else
            cout << "INSIDE\n";


    }
    return 0;
}