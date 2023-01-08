// Problem: E. Permutation Game
// Contest: Codeforces - Codeforces Round #839 (Div. 3)
// URL: https://codeforces.com/contest/1772/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define IOS  ios::sync_with_stdio(false);
#define CIT  cin.tie(0);
#define COT  cout.tie(0);

#define ll long long
#define x first
#define y second
#define pb push_back
#define endl '\n'
#define all(a) std::begin(a), std::end(a)
#define Fup(i,a,b) for(int i=a;i<=b;i++)
#define Fde(i,a,b) for(int i=a;i>=b;i--)

template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }



#define NO cout<<"NO"<<endl;
#define YES cout<<"YES"<<endl;


const int N = 2e5+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};





void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    Fup(i,0,n-1) cin>>a[i];
    ll maxn=0;
    Fup(i,0,n-2)
    {
        ll val=ceil(double(a[i]+a[i+1])/2);
        if(a[i]>a[i+1])
            maxn=max(maxn,val);
    }
    Fup(i,0,n-1)
    {
        a[i]=abs(a[i]-maxn);
    }
    if(!is_sorted(all(a)))
    {
        cout<<-1<<endl;
        return;
 
    }
    cout<<maxn;
    cout<<endl;
 
  
}
int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
