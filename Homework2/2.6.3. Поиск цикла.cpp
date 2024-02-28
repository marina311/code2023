#include <bits/stdc++.h>

using namespace std;


struct Node {
    int b;
    Node *next;
};

const int MAXN = 100001;
Node *a[MAXN];
int from[MAXN], used[MAXN];
int n, m;

void add_vertex(int x, int y) {
    Node *p = new Node;
    p->b = y;
    p->next = a[x];
    a[x] = p;
}


void print_path(int t, int start) {
    if (t == start) {
        cout << start << ' ';
        return;
    }
    print_path(from[t], start);
    cout << t << ' ';
}

void dfs(int t) {
    Node *p = a[t];
    if (used[t] == 1) {
        cout << "YES" << endl;
        print_path(from[t], t);
        exit(0);
    }
    used[t] = 1;
    while (p != nullptr) {
        int y = p->b;
        from[y] = t;
        dfs(y);
        p = p->next;
    }
    used[t] = 2;
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        add_vertex(x, y);
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }

    cout << "NO";

    return 0;
}