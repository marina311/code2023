#include <bits/stdc++.h>

const int maxn = 130;
int n;
int t[maxn][maxn][maxn];


using namespace std;


long long sum(int r1, int r2, int r3) {
    long long res = 0;
    for (int i = r1; i > 0; i -= i & -i)
        for (int j = r2; j > 0; j -= j & -j)
            for (int k = r3; k > 0; k -= k & -k)
                res += t[i][j][k];
    return res;
}

long long sum(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sum(x2, y2, z2) - sum(x2, y2, z1) - sum(x1, y2, z2) - sum(x2, y1, z2) +
           sum(x1, y2, z1) + sum(x2, y1, z1) + sum(x1, y1, z2) - sum(x1, y1, z1);
}


void add(int x, int y, int z, int d) {
    for (int i = x; i <= maxn; i += i & -i)
        for (int j = y; j <= maxn; j += j & -j)
            for (int k = z; k <= maxn; k += k & -k)
                t[i][j][k] += d;
}

int main() {
    int n;
    cin >> n;
    while (true) {
        int q;
        cin >> q;
        if (q == 3) break;
        if (q == 1) {
            int x, y, z, k;
            cin >> x >> y >> z >> k;
            add(x + 1, y + 1, z + 1, k);
        } else {

            int x1, y1, z1, x2, y2, z2;

            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << sum(x1, y1, z1, x2 + 1, y2 + 1, z2 + 1) << "\n";
        }
    }
    return 0;
}