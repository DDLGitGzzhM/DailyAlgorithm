#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;

int stk[N],tt;
int n;


int main() {
    cin>>n;
    for(int i = 1; i <= n ;i ++ ) {
        int x;cin>>x;
        while(stk[tt] >= x) {
            tt -- ;
        }
        if(!tt) {
            cout<<-1<<" ";
        }else {
            cout<<stk[tt]<<" ";
        }
        stk[++tt] = x;
    }
    return 0;
}
// 3 -1
// 3,4