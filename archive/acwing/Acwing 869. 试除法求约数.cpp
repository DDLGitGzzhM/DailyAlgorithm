#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+10;
int n;

vector<int> getDiv(int x){ 
    vector<int> ans ;
    for(int i = 1; i <= x/ i ; i ++ ) {
        if(x % i == 0) {
            ans.push_back(i);
            if(i != x /i ) {
                ans.push_back(x/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans ;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  while(n -- ) {
    int x;cin>>x;
    auto ans = getDiv(x);
    for(auto res : ans) {
        cout<<res<<" ";
    }
    cout<<endl;
  }
  return 0;
}
