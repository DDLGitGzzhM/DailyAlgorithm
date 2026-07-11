#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10;

int n,k;
int a[N],q[N];

int main() {
    cin>>n>>k;
    int hh = 0 ,tt = -1;
    for(int i = 1 ; i <= n ; i ++ ) cin>>a[i];
    for(int i = 1; i <= n ; i ++ ) {
        if(hh <= tt && i - k  >= q[hh]) hh ++ ;
        while(hh <= tt && a[q[tt]] >= a[i]) tt -- ; // 5 6 2
        q[++tt] = i ;
        if(i-k >= 0) cout<<a[q[hh]]<<" "; 
    }
    hh = 0, tt = -1;
    cout<<endl;

    for(int i = 1; i <= n ; i ++ ) {
        if(hh <= tt && i - k  >= q[hh]) hh ++ ;
        while(hh <= tt && a[q[tt]] <= a[i]) tt -- ; // 5 6 2
        q[++tt] = i ;
        if(i-k >= 0) cout<<a[q[hh]]<<" "; 
    }
}

// 1 ,2,3,4,5