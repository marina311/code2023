#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> q1, q2;
    while (n--) {
        char c;
        cin >> c;
        if (c == '+') {
            int k;
            cin >> k;
            q2.push_back(k);
            if (q1.size() < q2.size()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        } else if (c == '*') {
            int k;
            cin >> k;
            if (q1.size() == q2.size()) {
                q1.push_back(k);
            } else {
                q2.push_front(k);
            }
        } else {
            cout << q1.front() << "\n";
            q1.pop_front();
            if (q1.size() < q2.size()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        }
    }
    return 0;
}