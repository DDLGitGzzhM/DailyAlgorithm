#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 10; 
int a[N],b[N];
int n,m,x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x;
    for(int i =1 ; i <= n ; i ++ ) cin >> a[i] ;
    for(int i = 1; i <= m ;i ++ ) cin>>b[i];

    int j = m ;
    for(int i = 1; i <= n ;i ++ ) {
        while(j >= 1 && x - a[i] < b[j]) {
            j -- ;
        }
        if(a[i] + b[j] == x) {
            cout<<i-1<<" "<<j-1<<endl;
            return 0;
        }
    }
    
    return 0;
}