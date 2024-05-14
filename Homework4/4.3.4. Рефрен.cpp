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

vector<int> buildLCP(vector<int> st, vector<int> suf) {
    //https://neerc.ifmo.ru/wiki/index.php?title=Алгоритм_Касаи_и_др.
    int n = st.size();
    vector<int> lcp(n);
    vector<int> pos(n);  // pos[] — массив, обратный массиву suf
    for (int i = 0; i < n; ++i)
        pos[suf[i]] = i;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (k > 0)
            k--;
        if (pos[i] == n - 1) {
            lcp[n - 1] = -1;
            k = 0;
            continue;
        } else {
            int j = suf[pos[i] + 1];
            while (max(i + k, j + k) < n and st[i + k] == st[j + k])
                k++;
            lcp[pos[i]] = k;
        }
    }
    return lcp;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    s.push_back(0);
    vector<int> sm = sufmas(s);
    vector<int> lcp = buildLCP(s, sm);
    // Воспользуемся свойством: LCP между двумя суффиксами — 
    // минимум LCP всех пар соседних суффиксов между ними в суффиксном массиве.
    // Для каждого i найдем максимальный отрезок, на котором LCP является минимумом
    vector<int> left(n + 1), right(n + 1);
    stack<int> st;
    st.push(0);
    lcp[0] = -1;
    for (int i = 1; i < n; ++i) {
        while (lcp[i] <= lcp[st.top()]) st.pop();
        left[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    sm.push_back(0);
    st.push(n);
    for (int i = n - 1; i > 0; --i) {
        while (lcp[i] <= lcp[st.top()]) st.pop();
        right[i] = st.top();
        st.push(i);
    }
    int max_refren = 0;
    int max_len = n;
    long long best = n;
    for (int i = 1; i < n; ++i) {
        if (1LL *(right[i] - left[i]) * lcp[i] > best) {
            best = 1ll * (right[i] - left[i]) * lcp[i];
            max_len = lcp[i];
            max_refren = sm[left[i] + 1];
        }
    }
    cout << best << "\n" << max_len << "\n";
    for (int i = 0; i < max_len; ++i)
        cout << s[max_refren + i] << " ";
    return 0;
}