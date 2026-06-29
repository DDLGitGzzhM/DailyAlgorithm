#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int l,r,n ,m ;
int a[N];
long long s[N];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n>>m;
    for(int i = 1; i <= n ; i ++ ) cin>>a[i];
    for(int i = 1; i <= n ; i ++) s[i] = s[i-1] + a[i];
    while(m -- ) {
        int l , r ;  cin >> l >> r;
        cout<<s[r] - s[l-1]<<endl;
    }
}