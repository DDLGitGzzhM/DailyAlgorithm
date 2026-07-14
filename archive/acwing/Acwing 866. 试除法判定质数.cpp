#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;
bool isPrime(int x) {
    if(x < 2) return false ;
    for(int i = 2 ; i <= x /i ; i ++ )  {
        if(x % i == 0 ) {
            return false ;
        }
    }
    return true ;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;
  for(int i =1 ; i <= n ; i ++ ) {
    int x;cin>>x;
    if(isPrime(x) ) {
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
  }
  return 0;
}
