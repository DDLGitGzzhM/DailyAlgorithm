#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;

void SplitPrime(int x) {
    for(int i = 2 ;i <=  x / i ; i ++ ) {
        if(n % i == 0 ) {
            int s = 0 ;
            while(x % i == 0 ) {
                x /= i ;
                s ++ ;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x > 1) {
        cout<<x<<" "<<1<<endl;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
   
  for(int i = 1; i <= n ; i ++ ) {
    int x;cin>>x;
    SplitPrime(x);
    cout<<endl;
  }
  return 0;
}
