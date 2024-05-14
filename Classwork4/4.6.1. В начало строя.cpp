#include <bits/stdc++.h>

using namespace std;


struct Node {
    int key, prior;
    Node *l = 0, *r = 0;
    int size = 1;

    Node(int key) : key(key), prior(rand()) {}

    ~Node() {
        if (l != nullptr)
            delete[] l;
        if (r != nullptr)
            delete[] r;
    }
};

void update_size(Node *root) {
    if (root == nullptr)
        return;
    root->size = 1;
    if (root->l != nullptr)
        root->size += root->l->size;
    if (root->r != nullptr)
        root->size += root->r->size;
}

void update_size_tree(Node *root) {
    if (root == nullptr)
        return;
    root->size = 1;
    update_size_tree(root->l);
    if (root->l != nullptr)
        root->size += root->l->size;
    update_size_tree(root->r);
    if (root->r != nullptr)
        root->size += root->r->size;
}

int get_size(Node *root) {
    return (root == nullptr) ? 0 : root->size;
}

Node *merge(Node *l, Node *r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update_size(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update_size(r);
        return r;
    }
}

pair<Node *, Node *> split(Node *p, int k) {
    // Разбиваем дерево так, что в левом поддереве будет k вершин
    if (p == nullptr) return {nullptr, nullptr};
    if (get_size(p) <= k)
        return {p, nullptr};
    if (k == 0)
        return {nullptr, p};
    if (get_size(p->l) >= k) {
        auto [l, r] = split(p->l, k);
        p->l = r;
        update_size(p);
        return {l, p};
    } else {
        auto [l, r] = split(p->r, k - get_size(p->l) - 1);
        p->r = l;
        update_size(p);
        return {p, r};
    }
}

Node *build(int n) {
    Node *root = nullptr;
    for (int val = 1; val <= n; ++val) {
        Node *newnode = new Node(val);
        root = merge(root, newnode);
    }
    return root;
}


void print(Node *root) {
    if (root == nullptr)
        return;
    print(root->l);
    cout << root->key << " ";
    print(root->r);
}

int main() {
    int n, m;
    cin >> n >> m;
    Node *root = build(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        auto split1 = split(root, r);
        auto split2 = split(split1.first, l - 1);
        root = merge(merge(split2.second, split2.first), split1.second);
    }
    print(root);
    cout << "\n";
    return 0;
}