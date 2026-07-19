#include <bits/stdc++.h>
#define LL long long
using namespace std;
typedef pair<int,int>  PII ;

int n;

int e[N],ne[N],idx,head ;

void init()  {
  head = -1;
  idx = 0 ;
}


void add_to_head(int x) {
  e[idx] = x ;
  ne[idx] = h ;
  idx ++ ;
}

void add(int k,int x) {
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


  return 0;
}
