#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10, mod = 1e9+7;

int phi(int x) {
  int res = x ;
  for(int i = 2; i <= x/ i ; i ++ ) {
      
    if(x % i == 0 ) {
      res = res - res/i;
      while(x % i == 0 ) x/=i ; 
    }
  }
if(x > 1) res = res  - res / x ;
  return res; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  while(n -- ) {
    int x;cin>>x;
    cout<<phi(x)<<endl;
  }

  return 0;
}
