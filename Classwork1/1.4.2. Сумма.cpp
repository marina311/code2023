#include <bits/stdc++.h>

using namespace std;

vector<long long> tree(200000, 0);

void build(int n) {
    for (int i = n - 1; i > 0; --i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

void add(int n, int pos, int value) {
    pos += n;
    tree[pos] = value;
    pos /= 2;
    while (pos > 0) {
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        pos /= 2;
    }
}

long long res(int n, int l, int r) {
    l += n;
    r += n;
    long long ans = 0;
    while (l < r) {
        if (l % 2 == 1) ans += tree[l++];
        if (r % 2 == 1) ans += tree[--r];
        l /= 2;
        r /= 2;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    build(n);
    while (k--) {
        char c;
        cin >> c;
        if (c == 'A') {
            int i, x;
            cin >> i >> x;
            add(n, i - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << res(n, l - 1, r) << "\n";
        }
    }


    return 0;
}