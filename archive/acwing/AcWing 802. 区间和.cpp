#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;
 
int head, e[N], ne[N], idx ;

void init() {
    head = -1 ;
    idx = 0 ;
}


void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head ;
    head = idx ++ ;
}

void add(int k ,int x) {
    e[idx] = x ;
    ne[idx] = ne[k];
    ne[k] = idx ++ ; 
}
// 1 , ne[0] = -1
// 2 , ne[1] = 0
// 3 , ne[2] = 1

// 5 , ne[4] = ne[3-1] = 1 ; 3, 1 (ne[3] = 5)

// 4 , ne[3] = 2


void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int n;cin>>n;
    init();
    for(int i = 1 ; i<= n ; i ++ ) {
        char op ;cin >> op ;
        if (op == 'H') {
            int x;cin>>x;
            add_to_head(x);
        }else if (op == 'D') {
            int x;cin>>x;
            if (!x) head = ne[head]; 
            else remove(x-1);
        }else if (op == 'I') {
            int k,x;cin>>k>>x;
            add(k-1,x);
        }
    }

    for(int i = head ; i != -1 ; i = ne[i]) {
        cout<<e[i]<<" ";
    }

    return 0;
}