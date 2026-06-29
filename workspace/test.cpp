#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 10; 
int a[N],n;
int has[N] ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    int ans = 0 ;
    int j = 1;
    for(int i = 1; i <= n ; i ++ ) {
        has[a[i]] ++ ;
        while(j <= i && has[a[i]] > 1) {
            has[a[j]] -- ;
            j ++ ;
        }
        ans = max(ans, i - j + 1);
    }
    cout<<ans<<endl;
    return 0;
}