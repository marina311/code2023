﻿#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    Deque d;
    while (cin >> s) {
        if (s == "exit") {
            cout << "bye\n";
            break;
        } else if (s == "push_front") {
            int x;
            cin >> x;
            d.push_front(x);
            cout << "ok\n";
        } else if (s == "push_back") {
            int x;
            cin >> x;
            d.push_back(x);
            cout << "ok\n";
        } else if (s == "pop_front") {
            if (d.empty()) {
                cout << "error\n";
            } else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } else if (s == "pop_back") {
            if (d.empty()) {
                cout << "error\n";
            } else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        } else if (s == "clear") {
            while (!d.empty()) {
                d.pop_back();
            }
            cout << "ok\n";
        } else if (s == "front") {
            if (d.empty()) {
                cout << "error\n";
            } else {
                cout << d.front() << '\n';
            }
        } else if (s == "back") {
            if (d.empty()) {
                cout << "error\n";
            } else {
                cout << d.back() << '\n';
            }
        } else if (s == "size") {
            cout << d.size() << '\n';
        }
    }
}