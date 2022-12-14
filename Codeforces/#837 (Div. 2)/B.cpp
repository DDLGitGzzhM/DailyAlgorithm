// Problem: B. Hossam and Friends
// Contest: Codeforces - Codeforces Round #837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define IOS  ios::sync_with_stdio(false);
#define CIT  cin.tie(0);
#define COT  cout.tie(0);
#define int long long
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



int n,m;
int r[N];

void solve(){
	cin>>n>>m;
	
	Fup(i,1,n) r[i] = n + 1;
	
	
	Fup(i,1,m){
		int a,b;cin>>a>>b;
		if(a > b) swap(a,b);
		r[a] = min(r[a],b);		
	}
	
	Fde(i,n-1,1){
		if(r[i] > r[i+1]) r[i] = min(r[i] , r[i+1]);
	}
	
	int ans = 0 ;
	
	Fup(i,1,n){
		ans += r[i] - i ;
	}
	cout<<ans<<endl;
	
}

signed main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
