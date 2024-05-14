#include <bits/stdc++.h>

using namespace std;


const int MAXN = 1e5 + 5;
int a[MAXN];
vector<int> b[MAXN / 256 + 2];

void rebuild_bucket(int idx, int bucket_size) {
    int l = idx * bucket_size, r = min(l + bucket_size, MAXN);
    b[idx].clear();
    for (int i = l; i < r; ++i) {
        b[idx].push_back(a[i]);
    }
    sort(b[idx].begin(), b[idx].end());
}

int query(int l, int r, int x, int bucket_size) {
    int cnt1 = 0, cnt2 = 0;
    while (l <= r) {
        if (l % bucket_size == 0 && l + bucket_size - 1 <= r) {
            int idx = l / bucket_size;
            cnt1 += lower_bound(b[idx].begin(), b[idx].end(), x) - b[idx].begin();
            cnt2 += bucket_size - (upper_bound(b[idx].begin(), b[idx].end(), x) - b[idx].begin());
            l += bucket_size;

        } else {
            if (a[l] < x) cnt1++;
            if (a[l] > x) cnt2++;
            l++;
        }
    }

    //   cout << cnt1 << " " << cnt2 << "\n";
    if (cnt1 > cnt2) return 1;
    if (cnt1 < cnt2) return 2;
    return 0;
}

int main() {
    //   freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    int bucket_size = sqrt(n) + 1; // 500

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= 2;
        b[i / bucket_size].push_back(a[i]);
    }

    for (int i = 0; i <= n / bucket_size; ++i) {
        sort(b[i].begin(), b[i].end());
    }
    cin >> m;

    while (m--) {
        string type;
        int value, x;
        cin >> type;
        if (type == "C") {
            cin >> x >> value;
            --x;
            a[x] = 2 * value;
            rebuild_bucket(x / bucket_size, bucket_size);

        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1;
            --x2;
            cout << query(x1, x2, y1 + y2, bucket_size) << "\n";
        }
    }

    return 0;
}

