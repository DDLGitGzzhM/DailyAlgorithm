#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;

int q[N];

int tt,hh;

void init() {
    tt = -1;
}

bool empty() {
    return (hh <= tt);
}

void add(int x) {
    q[++tt] = x;
}

void pop() {
    hh ++ ;
}

int query() {
    return q[hh];
}


int main() {
    init();
    int m;cin>>m;
    while(m -- ) {
        string op;cin>>op;
        if(op == "push") {
            int x;cin>>x;
            add(x);
        }else if(op == "pop"){
            pop();
        }else if(op == "empty") {
            if(empty()) {
                cout<<"NO"<<endl;
            }else {
                cout<<"YES"<<endl;
            }
        }else if(op == "query") {
            cout<<query()<<endl;
        }
    }
    return 0;
}