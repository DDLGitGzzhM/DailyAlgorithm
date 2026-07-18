#include <bits/stdc++.h>
#define LL long long
using namespace std;
typedef pair<int,int>  PII ;

const int N = 110;
int n,m;
int g[N][N],d[N][N];
PII q[N * N] ;

void bfs() {
   int hh = 0 ,tt = 0 ;
   memeset(d,-1,sizeof(d));
   q[0] = {1,1};
   d[0][0] =  0 ;
   
   int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
   while(hh <= tt) {
      auto t = q[hh ++ ];
      for(int i = 0 ; i < 4 ; i ++ ) {
        int fx = t.first + dx[i];
        int fy = t.second + dy[i];
        if(fx  < 1 || fx  > n) continue ;
        if(fy  < 1 || fy  > m) continue ;
        if(g[fx][fy] == 1) continue ;
        if(d[fx][fy] != -1) continue ;
        
        d[fx][fy] = d[t.first][t.second] + 1;
        q[++tt] = {fx,fy};
      }
   }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i = 1; i <= n ; i ++ ) {
    for(int j = 1; j <= m ; j ++ ) {
      cin>>g[i][j];
    }
  }
  bfs();
  cout<<d[n][m]<<endl;
  return 0;
}
