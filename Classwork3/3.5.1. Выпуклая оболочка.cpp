#include <bits/stdc++.h>

using namespace std;

using T = long long;

struct Vector {
    T x;
    T y;

    Vector(T x = 0, T y = 0) : x(x), y(y) {};

    Vector(const Vector &a, const Vector &b) {
        x = b.x - a.x;
        y = b.y - a.y;
    };

    T len2() const {
        return x * x + y * y;
    }
};
istream &operator>>(istream &is, Vector &p) {
    is >> p.x >> p.y;
    return is;
}

ostream &operator<<(ostream &os, Vector &p) {
    os << p.x << " " << p.y;
    return os;
}

Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x - b.x, a.y - b.y);
}

T operator*(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}

T operator&(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}

bool operator==(const Vector &a, const Vector &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator<(const Vector &a, const Vector &b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

void polarSort(vector<Vector> &points, const Vector &s) {
    sort(points.begin(), points.end(), [&](const Vector &a, const Vector &b) -> bool {
        const Vector p1(s, a), p2(s, b);
        if ((p1 & p2) == 0)
            return p1.len2() < p2.len2();
        return (p1 & p2) > 0;
    });
}

vector<Vector> convexHull(vector<Vector> &points) {
    const Vector s = *min_element(points.begin(), points.end());
    polarSort(points, s);
    vector<Vector> st;
    for (const Vector &point: points) {
        while (st.size() >= 2) {
            if (((point - st.back()) & (st[st.size() - 2] - st.back())) > 0)
                break;
            st.pop_back();
        }
        st.push_back(point);
    }
    return st;
}


int main() {
    int n;
    cin >> n;
    vector<Vector> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    vector<Vector> hull = convexHull(points);
    cout << hull.size() << "\n";
    for (auto p: hull) {
        cout << p << "\n";
    }
    return 0;
}