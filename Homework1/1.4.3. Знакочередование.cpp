#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<long long> tree;


void build() {
    tree.assign(2 * n, 0);
    for (int i = 0; i < n; ++i) {
        tree[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; i--)
        tree[i] = tree[i << 1] + tree[(i << 1) | 1];
}

void update(int i, int value) {
    if (i & 1) value = -value;
    i += n;
    tree[i] = value;
    i >>= 1;
    while (i > 0) {
        tree[i] = tree[i << 1] + tree[(i << 1) | 1];
        i >>= 1;
    }
}

long long count(int l, int r) {
    long long ans = 0;
    int sign = (l & 1) ? -1 : 1;
    l += n;
    r += n;
    while (l < r) {
        if (r & 1) ans += tree[--r];
        if (l & 1) ans += tree[l++];
        r >>= 1;
        l >>= 1;
    }
    return ans * sign;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i & 1) a[i] = -a[i];
    }
    build();
    int q;
    cin >> q;
    while (q--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == '1')
            cout << count(x - 1, y) << "\n";
        else
            update(x - 1, y);
    }
    return 0;
}