#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10;
int n;
bool st[N];

void filterPrime() {
    int cnt = 0 ;
    for(int i  = 2; i <=  n ; i ++ ) {
        if(!st[i]) {
            for(int j = i ; j <= n ; j += i  ) st[j] = 1;
            cnt ++ ;
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
