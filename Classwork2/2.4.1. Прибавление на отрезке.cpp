#include <bits/stdc++.h>

using namespace std;

int n;
int logn;
vector<int> a;
vector<long long> tree;
vector<long long> add;


void build() {
    tree.assign(2 * n, 0);
    add.assign(n, 0);
    logn = 32 - __builtin_clz(2 * n);
    for (int i = 0; i < n; ++i) {
        tree[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; i--)
        tree[i] = max(tree[i << 1], tree[(i << 1) | 1]);
}


void update_vertex(int v, long long val) {
    tree[v] += val;
    if (v < n) {
        add[v] += val;
    }
}

void update_ancestors(int v) {
    v >>= 1;
    while (v > 0) {
        tree[v] = max(tree[v << 1], tree[(v << 1) | 1]) + add[v];
        v >>= 1;
    }
}

void do_push(int leaf) {
    for (int k = logn; k > 0; k--) {
        int v = (leaf >> k);
        update_vertex(v << 1, add[v]);
        update_vertex((v << 1) | 1, add[v]);
        add[v] = 0;
    }
}

void update_segment(int l, int r, int val) { // [l, r) += val
    l += n;
    r += n;
    int ql = l, qr = r;
    while (l < r) {
        if (l & 1) {
            update_vertex(l++, val);
        }
        if (r & 1) {
            update_vertex(--r, val);
        }
        l >>= 1;
        r >>= 1;
    }
    update_ancestors(ql);
    update_ancestors(qr - 1);
}

long long count(int l, int r) {
    long long ans = 0;
    l += n;
    r += n;
    do_push(l);
    do_push(r - 1);
    while (l < r) {
        if (l & 1) {
            ans = max(ans, tree[l++]);
        }
        if (r & 1) {
            ans = max(ans, tree[--r]);
        }
        r >>= 1;
        l >>= 1;
    }
    return ans;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    int q;
    cin >> q;
    while (q--) {
        char c;

        cin >> c;
        if (c == 'm') {
            int x, y;
            cin >> x >> y;
            cout << count(x - 1, y) << "\n";
        } else {
            int x, y, a;
            cin >> x >> y >> a;
            update_segment(x - 1, y, a);
        }
    }
    return 0;
}