// Problem: A. Bookshelf Filling
// Contest: Codeforces - The 17th Heilongjiang Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103688/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

ll a,b,n,m,h;

bool check(ll mid){
	ll l1 =  (b-a)*(n/b);
	ll l2 =  (h-b)*((n+mid)/b);
	return l1 + l2 + mid >= m ;
}
void solve(){
	
	cin>>a>>b>>n>>m>>h;
	
	ll l  = 1 , r =  m;
	while(l<=r){
		ll mid = (l+r)>>1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout<<n+l<<endl;
	

}

int main(){
	IOS
	CIT
	COT
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
