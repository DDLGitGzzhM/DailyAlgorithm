#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10, mod = 1e9+7;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>n;
  unordered_map<int,int> mp ;
  while(n -- ) {
    int x;cin>>x;
    for(int i = 2; i <= x / i; i++) {
        while(x % i == 0) {
            x /= i;
            mp[i]++;
        }
    }
    if(x > 1) mp[x]++;
  }
  LL ans  = 1;
  for(auto x : mp) {
    LL t = 1; 
    int a = x.second ; 
    while(a -- ) {
        t = (t * x.first + 1) % mod ;
    }
    ans = ans%mod * t %mod ;
    
  }
  cout<<ans<<endl;
  return 0;
}
