#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10, mod = 1e9+7;

int gcd(int a,int b) {
  return b ? gcd(b , a %b) : a; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  while(n -- ) {
    int a,b;cin>>a>>b;
    cout<<gcd(a,b)<<endl;
  }

  return 0;
}
