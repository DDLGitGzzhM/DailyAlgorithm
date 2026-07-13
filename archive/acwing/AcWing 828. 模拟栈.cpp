#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;

int stk[N], tt ;

bool checkEmpty() {
    return (tt == 0); 
}

void push(int x) {
    stk[++tt] = x; 
}

int pop() {
    int x = stk[tt];
    tt -- ;
    return x; 
}

int query() {
    return stk[tt];
}

int main() {
    int m; cin>>m ;
    while(m -- ) {
        string op;cin>>op;
        if(op == "push") {
            int x;cin>>x;
            push(x);
        }else if (op == "pop")  {
            pop();
        }else if(op == "empty") {
            if (checkEmpty()) {
                cout<<"YES"<<endl;
            }else {
                cout<<"NO"<<endl;
            }
        }else if(op == "query") {
            cout<<query()<<endl;
        }
    }
    return 0;
}