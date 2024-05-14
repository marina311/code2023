#include <bits/stdc++.h>

using namespace std;


struct Node {
    int key, prior;
    Node *l = 0, *r = 0;

    Node(int key) : key(key), prior(rand()) {}
};

Node *merge(Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        return l;
    } else {
        r->l = merge(l, r->l);
        return r;
    }
}

pair<Node *, Node *> split(Node *p, int x) {
    if (!p) return {0, 0};
    if (p->key < x) {
        auto [l, r] = split(p->r, x);
        p->r = l;
        return {p, r};
    } else {
        auto [l, r] = split(p->l, x);
        p->l = r;
        return {l, p};
    }
}

Node *root = 0;

void insert(int x) {
    auto [l, r] = split(root, x);
    Node *t = new Node(x);
    root = merge(l, merge(t, r));
}

bool exists(int x, Node *p) {
    if (!p) return 0;
    if (p->key == x) return 1;
    if (x < p->key) return exists(x, p->l);
    else return exists(x, p->r);
}


void del(int x) {
    if (!exists(x, root)) return;
    auto [l, r] = split(root, x);
    auto [l1, r1] = split(r, x + 1);
    root = merge(l, r1);
}


int main() {
    string s;
    while (cin >> s) {
        int x;
        cin >> x;
        if (s == "insert") insert(x);
        else if (s == "delete") del(x);
        else if (s == "exists") cout << (exists(x, root) ? "true" : "false") << "\n";
    }

    return 0;
}