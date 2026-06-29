#include <bits/stdc++.h>

using namespace std ;
const int N = 1e3+ 10 ;
int n,m,q;
int b[N][N];

void insert(int x1,int y1,int x2,int y2,int c) {
    b[x1][y1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -= c;
    b[x2+1][y2+1] += c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    cin>>n>>m>>q;
    for(int i = 1; i <= n ; i ++ )
        for(int j = 1 ; j <= m ; j ++ ){
            int c ;cin>>c;
            insert(i,j,i,j,c);
        }
    
    while(q -- ) {
        int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
        int c ; cin>>c;
        insert(x1,y1,x2,y2,c);
    }
    
    for(int i = 1; i <= n ; i ++ )
        for(int j = 1; j <= m ; j ++ )
        b[i][j] += ( b[i-1][j] + b[i][j-1] - b[i-1][j-1]);
    for(int i = 1; i<= n ; i ++ ) {
        for(int j = 1; j <= m ;j ++ ){
        cout<<b[i][j]<<" ";
         }
         cout<<endl;
    }
        
    return 0;
}