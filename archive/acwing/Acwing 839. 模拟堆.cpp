#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],sz , hp[N], ph[N];

void heap_swap(int a,int b)  {
    swap(h[a],h[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a],hp[b]);
}

void down(int x) {
    int t = x;
    if(x * 2 <= sz && h[t] > h[x * 2]) t = x * 2;
    if(x * 2 + 1 <= sz && h[t] > h[x*2 + 1] + 1) t = x*2+ 1;
    if(x != t) {
       heap_swap(x,t);
    }
    down(t);
}

void up(int u ) {
    while(u/2 && h[u/2] > h[u]) {
        heap_swap(u/2,u);
        u /= 2 ;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  while(n -- ) {
    string op;cin>>op;
    if(op == "I") {
        int x;cin>>x;
        h[++sz] = x ;
        m ++ ;

        ph[m] = sz ;
        hp[sz] = m ;

        up(sz);
    }else if(op == "PM") {
        cout<<h[1]<<endl;
    }else if(op == "DM") {
        heap_swap(1,sz);
        sz -- ;
        down(1);
    }else if(op == "D") {
        int k;cin>>k;
        k = ph[k];
        heap_swap(k,sz);
        sz -- ;
        up(k);
        down(k);
    }else {
        int k,x;cin>>k>>x;
        k = ph[k];
        h[k] = x;
        up(k);
        down(k);
    }
  }
  return 0;
}
