#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 10 ;

int e[N],ne[N],idx,head;

void init() {
  head = -1;
  idx = 0 ;
}

void add_to_head(int x) {
  e[idx] = x;
  ne[idx] = head;
  head = idx ++ ;
}

void add(int k , int x) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx ++ ;
}

void remove(int k) {
  ne[k] = ne[ne[k]];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int n;cin>>n;
  for(int i = 1; i <= n ;i ++ ) {
    char op;cin>>op;
    if(op == 'H') {
      int x;cin>>x;
      add_to_head(x);
    }else if(op == 'D') {
      int k;cin>>k;
      if(k == 0) {
        head = ne[head];
        continue ;
      }
      remove(k-1);
    }else {
      int k,x;cin>>k>>x;
      add(k-1,x);
    }
  }

  for(int i = head ; i != -1 ; i = ne[i]) cout<<e[i]<<" ";
  return 0;
}
