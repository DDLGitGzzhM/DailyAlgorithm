#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],sz ;

void down(int x) {
    int t = x;
    if(x * 2 <= sz && h[t] > h[x * 2]) t = x * 2;
    if(x * 2 + 1 <= sz && h[t] > h[x*2 + 1] ) t = x*2+ 1;
    if(h[x] != h[t]) {
        swap(h[x],h[t]);
        down(t);
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>n>>m;
  for(int i = 1; i <= n ; i ++ ) cin>>h[i];
  sz = n ;
  for(int i = n/2; i ; i -- ) down(i);
  while(m -- ) {
    cout<<h[sz]<<" ";
    h[1] = h[sz];
    sz -- ;
    down(1);
  }
  return 0;
}
