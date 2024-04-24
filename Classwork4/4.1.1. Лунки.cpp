#include <bits/stdc++.h>

using namespace std;


const int D = 500;
const int NMAX = 200001;
int n, m;
int a[NMAX];
int next_[NMAX];
int cnt[NMAX];
int last_[NMAX];

int main() {


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int z = ((n - 1) / D + 1) * D;
    for (int i = n - 1; i >= 0; i--) {
        int x = i + a[i];
        if (x >= n) x = z;
        int t = (i / D + 1) * D;
        if (x < t) {
            next_[i] = next_[x];
            cnt[i] = cnt[x] + 1;
            last_[i] = last_[x];
        } else {
            next_[i] = x;
            cnt[i] = 1;
            last_[i] = i;
        }
    }
    while (m--) {
        int r;
        cin >> r;
        if (r == 1) {
            int x;
            cin >> x;
            x--;
            int l = x, ans = 0;
            while (x < n) {
                ans += cnt[x];
                l = last_[x];
                x = next_[x];
            }
            cout << l + 1 << " " << ans << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            a[x] = y;
            int t = (x / D + 1) * D;
            int tt = t - D;
            for (int i = x; i >= tt; i--) {
                int q = a[i] + i;
                if (q >= n) q = z;
                if (q < t) {
                    next_[i] = next_[q];
                    cnt[i] = cnt[q] + 1;
                    last_[i] = last_[q];
                } else {
                    next_[i] = q;
                    cnt[i] = 1;
                    last_[i] = i;
                }
            }
        }
    }

    return 0;
}