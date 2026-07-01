#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 10; 
int a[N],b[N];
int n,m;
bool used[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    for(int i = 1 ; i <= m ; i ++) cin>>b[i];
    int cnt = 0 ;
    int j = 1; 

    for(int i = 1; i <= n ; i ++  ) {
        // cout<<"i: "<<i<<" a[i]: " << a[i] <<" find:" <<endl ;

        while(j <= m && (a[i] != b[j] || used[j])) {
            // cout<<"j :" << j << "b[j] "<< b[j] << endl ;
            j ++ ;
        }
        // cout<<"find end:" <<"i :"<<i<<" j: " << j <<endl;

        if(!used[j] && j <= m &&  a[i] == b[j] ) {
            cnt ++ ;
            used[j] = true;
        }
    }
    if(cnt == n) {
        cout<<"Yes";
    }else {
        cout<<"No";
    }
    return 0;
}