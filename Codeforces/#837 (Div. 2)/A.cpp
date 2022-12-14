// Problem: A. Hossam and Combinatorics
// Contest: Codeforces - Codeforces Round #837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/0
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
map<int,int> mp;

int a[N],n;

void solve(){
	mp.clear();
	
	cin>>n;
	int d = 0 ;
	
	Fup(i,1,n){
		cin>>a[i];
		mp[a[i]] ++ ;
	}
	
	sort(a+1,a+1+n);
	d = a[n] - a[1];
	
	if(a[1]!=a[n])	cout<<mp[a[n]]*mp[a[1]]*2ll<<endl;
	else cout<<mp[a[n]]*(mp[a[n]]-1)<<endl;
	

	
}

signed main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
