#include <bits/stdc++.h>

using namespace std;


const int maxn = 2000;
int n;
int t[maxn][maxn];

long long sum(int r1, int r2) {
    long long res = 0;
    for (int i = r1; i > 0; i -= i & -i)
        for (int j = r2; j > 0; j -= j & -j)
            res += t[i][j];
    return res;
}

long long sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x2, y1) - sum(x1, y2) + sum(x1, y1);
}


void add(int x, int y, int d) {
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= n; j += j & -j)
            t[i][j] += d;
}

int main() {
    int q;
    cin >> n >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "ADD") {
            int i, j;
            cin >> i >> j;
            add(i, j, 1);
        } else {

            int x1, y1, x2, y2;

            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);

            x1--;
            y1--;
            cout << sum(x1, y1, x2, y2) << "\n";
        }

    }
    return 0;
}