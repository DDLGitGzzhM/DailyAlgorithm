#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;

int p[N] ;

int find(int x) {
    if(p[x]!= x) {
        return p[x] = find(p[x]);
    }
    return p[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  for(int  i = 1 ; i <= n ; i ++ ) {
     p[i] = i ;
  }
  for(int i = 1 ; i <= m ; i ++ ) {
    char op;cin>>op ;
    int a,b;cin>>a>>b;
    int fa = find(a);
    int fb = find(b);
    if(op == 'M') {
        p[fa] = fb;
    }else if(op == 'Q') {
        if (fa == fb) {
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
  }
}
