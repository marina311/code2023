#include <bits/stdc++.h>

using namespace std;
vector<int *> tree;
int n;
int arr[100001];

void build(int arr[]) {
    tree.assign(2 * n, 0);
    for (int i = 0; i < n; i++) {
        tree[n + i] = &arr[i];
    }
    for (int i = n - 1; i > 0; i--) {
        if (*tree[i << 1] > *tree[(i << 1) | 1])
            tree[i] = tree[i << 1];
        else tree[i] = tree[(i << 1) | 1];
    }
}


int *find_max(int l, int r) { // [l, r)
    l += n;
    r += n;
    int *ans = tree[l];
    while (l < r) {
        if (l & 1) {
            if (*tree[l] > *ans)
                ans = tree[l];
            l++;
        }
        if (r & 1) {
            r--;
            if (*tree[r] > *ans)
                ans = tree[r];

        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

int main() {


    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    build(arr);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int *ans = find_max(l - 1, r);
        cout << *ans << " " << ans - arr + 1 << "\n";
    }


}