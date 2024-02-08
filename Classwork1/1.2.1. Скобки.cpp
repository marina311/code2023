#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    map<char, char> br = {{')', '('},
                          {']', '['},
                          {'}', '{'},};
    stack<char> st;
    bool ans = true;
    for (auto c : s) {
        if (br.find(c) != br.end()) {
            if (st.empty() || st.top() != br[c]) {
                ans = false;
                break;
            }
            st.pop();
        } else {
            st.push(c);
        }

    }
    if (!ans || !st.empty())
        cout << "NO";
    else
        cout << "YES";

    return 0;
}