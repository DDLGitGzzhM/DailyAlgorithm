#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10;
int n;
bool st[N];
int prime[N];
void filterPrime() {
    int cnt = 0 ;
    for(int i = 2; i <= n; i ++ )  {
        if(!st[i]) prime[++cnt] = i ;
        for(int j = 1 ; prime[j] <= n / i  ; j ++ ) {
            st[prime[j] * i] = 1 ;
            if(i % prime[j] == 0) break; 
        }
    }
    cout<<cnt<<endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  filterPrime();
  return 0;
}
