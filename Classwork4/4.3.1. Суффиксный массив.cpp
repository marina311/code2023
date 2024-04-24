#include <bits/stdc++.h>

using namespace std;

vector<int> sufmas(vector<int> c) {
    // https://codeforces.com/blog/entry/66540
    int n = c.size();
    vector<pair<pair<int, int>, int>> t(n); //t[i] = { { first class, second class }, position }
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < c.size(); j++)
            t[j] = {{c[j], c[(j + i) % n]}, j};
        sort(t.begin(), t.end());
        for (int cnt = 0, j = 0; j < n; j++) {
            if (j && t[j].first != t[j - 1].first)
                cnt++;
            c[t[j].second] = cnt;
        }
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[c[i]] = i;
    return p;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> s;
    char c;
    while (cin >> c)
        s.push_back(c);
    s.push_back('$');
    auto sm = sufmas(s);
    for (auto x: sm)
        if (s[x] != '$') cout << x + 1 << " ";
    return 0;
}