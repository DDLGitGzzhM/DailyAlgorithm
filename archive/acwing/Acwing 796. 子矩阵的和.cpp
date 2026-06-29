#include <bits/stdc++.h>

using namespace std ;
const int N = 1e3+ 10 ;
int a[N][N];
long long s[N][N];
int n,m,q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++ ) 
        for(int j = 1; j <= m ; j ++ ) {
            cin>>a[i][j];
            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    
    while(q -- ) {
        int x1,y1,x2,y2 ;
        cin >> x1>>y1>>x2>>y2;
        cout<< s[x2][y2] - s[x2][y1-1]  - s[x1-1][y2] + s[x1-1][y1-1]<<endl;
    }

    
    return 0;
}