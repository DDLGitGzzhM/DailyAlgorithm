a#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
int n,q,k ;
int a[N];

int main() {
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    while(q --  ) {
        int x ; cin>>x;
        int l = 1 , r = n ;
        
        while(l < r) {
            int mid = l+r>>1;
            if(a[mid] >= x) r = mid ;
            else l = mid + 1; 
        }
        if(a[l] != x) {
            cout<<"-1 -1"<<endl;
        }else {
            cout<<l-1<<" ";
            l = 1,  r= n ;
            while(l < r) {
                int mid = l+r+1>>1;
                if(a[mid] <= x) l = mid;
                else r = mid - 1; 
            }
            cout<<r-1<<endl;
        }
    }
}