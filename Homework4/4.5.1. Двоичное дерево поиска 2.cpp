#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;
const int INF = 2000000000;

struct Node {
    int key, prior;
    Node *l = 0, *r = 0;
    int cnt = 0;

    Node(int key) : key(key), prior(rand()) {
        cnt = 1;
    }

    ~Node() {
        if (l != nullptr)
            delete[] l;
        if (r != nullptr)
            delete[] r;
    }
};

long long get_cnt(Node *root) {
    return (root == nullptr) ? 0 : root->cnt;
}

void print(Node *t) {
    if (t == nullptr) {
        return;
    }
    cout << t->key << " " << t->cnt;
    cout << " l:";
    print(t->l);
    cout << " r:";
    print(t->r);

}

void update_cnt(Node *root) {
    if (root == nullptr)
        return;
    root->cnt = 1 + get_cnt(root->l) + get_cnt(root->r);
}

Node *merge(Node *l, Node *r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update_cnt(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update_cnt(r);
        return r;
    }
}

pair<Node *, Node *> split(Node *p, int x) {
    if (p == nullptr) return {nullptr, nullptr};
    if (p->key < x) {
        auto [l, r] = split(p->r, x);
        p->r = l;
        update_cnt(p);
        return {p, r};
    } else {
        auto [l, r] = split(p->l, x);
        p->l = r;
        update_cnt(p);
        return {l, p};
    }
}

bool exists(int x, Node *p) {
    if (p == nullptr) return 0;
    if (p->key == x) return 1;
    if (x < p->key) return exists(x, p->l);
    else return exists(x, p->r);
}

Node *root = nullptr;

void insert(int x) {
    if (exists(x, root)) return;
    auto [l, r] = split(root, x);
    Node *t = new Node(x);
    root = merge(l, merge(t, r));
}

void del(int x) {
    if (!exists(x, root)) return;
    auto [l, r] = split(root, x);
    auto [l1, r1] = split(r, x + 1);
    root = merge(l, r1);
}


int kth(int k, Node *p) {
    if (get_cnt(p) < k)
        return -INF;
    if (get_cnt(p->l) >= k)
        return kth(k, p->l);
    if (get_cnt(p->l) + 1 == k)
        return p->key;
    return kth(k - get_cnt(p->l) - 1, p->r);
}

int lower(Node *p) {
    return p->l == nullptr ? p->key : lower(p->l);
}

int high(Node *p) {
    return p->r == nullptr ? p->key : high(p->r);
}

int prev(int key) {
    auto [l, r] = split(root, key);
    int res = (l == nullptr ? -INF : high(l));
    root = merge(l, r);
    return res;
}

int next(int key) {
    auto [l, r] = split(root, key);
    int res = (r == nullptr ? -INF : lower(r));
    root = merge(l, r);
    return res;
}


int main() {
    freopen("input.txt", "r", stdin);
    string s;
    while (cin >> s) {
        //       cout << "\n";
        //       print(root);
        int x;
        cin >> x;
        if (s == "insert") {
            insert(x);
        } else if (s == "exists") {
            cout << (exists(x, root) ? "true\n" : "false\n");
        } else if (s == "delete") {
            del(x);
        } else if (s == "next") {
            int res = next(x);
            if (res != -INF)
                cout << res << "\n";
            else cout << "none\n";
        } else if (s == "prev") {
            int res = prev(x);
            if (res != -INF)
                cout << res << "\n";
            else cout << "none\n";

        } else if (s == "kth") {
            int res = kth(x, root);
            if (res != -INF)
                cout << res << "\n";
            else cout << "none\n";
        }

    }
    return 0;
}