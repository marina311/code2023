#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    queue <int> q;
    while (true){
        string s;
        cin>>s;
        if (s=="push"){
            int x;
            cin>>x;
            q.push(x);
            cout<<"ok"<<endl;
        }
        else if (s=="pop"){
            if (q.size()>=1){
                cout<<q.front()<<endl;
                q.pop();
            }
            else {
                cout<<"error"<<endl;
            }
        }
        else if (s=="front"){
            if (q.size()>=1){
                cout<<q.front()<<endl;
            }
            else {
                cout<<"error"<<endl;
            }
        }
        else if (s=="size"){
            cout<<q.size()<<endl;
        }
        else if (s=="clear"){
            while (!q.empty()) {
                q.pop();
            }
            cout<<"ok"<<endl;
        }
        else if (s=="exit"){
            cout<<"bye"<<endl;
            return 0;
        }
    }
}