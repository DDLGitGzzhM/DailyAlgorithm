#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10, mod = 1e9+7;
int n;
bool st[10];
int ans[N];

void dfs(int u) {
  if( u == n + 1 ) {
    for(int i = 1;i <= n ; i ++ ) cout<<ans[i]<<" ";
    cout<<endl;
    return ;
  }

  for(int i = 1 ; i<= n ; i ++ ) {
    if(!st[i]) {
        st[i] = 1;
        ans[u] = i ;
        dfs(u + 1);
        st[i] = 0 ;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>n;
  dfs(1);
  return 0;
}
