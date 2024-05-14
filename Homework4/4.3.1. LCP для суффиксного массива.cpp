#include <bits/stdc++.h>

using namespace std;
}

vector<int> buildLCP(string st, vector<int> suf) {
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.push_back('$');
    vector<int> sm(n + 1);
    sm[0] = n;
    for (int i = 1; i <= n; ++i){
        cin >> sm[i];
        sm[i]--;
    }
    vector<int> res = buildLCP(s, sm);
    for (int i = 1; i < n; ++i)
        cout << res[i] << " ";
    return 0;
}