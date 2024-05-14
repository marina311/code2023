#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000000;

struct Node {
    int key, prior;
    Node *left = 0, *right = 0;
    int size = 1;
    int min = key;

    Node(int key) : key(key), prior(rand()) {
    }

};

int get_size(Node *root) {
    return (root == nullptr) ? 0 : root->size;
}

int get_min(Node *root) {
    return (root == nullptr) ? INF : root->min;
}


void update(Node *root) {
    if (root == nullptr)
        return;
    root->size = 1 + get_size(root->left) + get_size(root->right);
    root->min = min(root->key, min(get_min(root->left), get_min(root->right)));

}


Node *merge(Node *l, Node *r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    if (l->prior > r->prior) {
        l->right = merge(l->right, r);
        update(l);
        return l;
    } else {
        r->left = merge(l, r->left);
        update(r);
        return r;
    }
}

pair<Node *, Node *> split(Node *p, int i) {
    if (p == nullptr) return {nullptr, nullptr};
    int left_size = get_size(p->left);
    if (left_size >= i) {
        auto [l, r] = split(p->left, i);
        p->left = r;
        update(p);
        return {l, p};
    } else {
        auto [l, r] = split(p->right, i - left_size - 1);
        p->right = l;
        update(p);
        return {p, r};
    }
}

Node *root = nullptr;

void insert(int i, int x) {

    auto [l, r] = split(root, i);
    Node *t = new Node(x);
    root = merge(l, merge(t, r));
}


int get_result(int x, int y, Node *p) {
    auto [l, r] = split(p, x - 1);
    auto [l1, r1] = split(r, y - x + 1);
    int res = get_min(l1);
    root = merge(l, merge(l1, r1));
    return res;
}

void print_tree(Node *root){
    if (!root) return;
    print_tree(root->left);
    cout << root->key << " ";
    print_tree(root->right);


}


int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s == "+") {
            int i, x;
            cin >> i >> x;
            insert(i, x);

        } else if (s == "?") {
            int x, y;
            cin >> x >> y;
            cout << get_result(x, y,root) << "\n";
        }
//       print_tree(root);
        //       cout << "\n";
    }
    return 0;
}