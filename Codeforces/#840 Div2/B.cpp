// Problem: B. Incinerate
// Contest: Codeforces - Codeforces Round #840 (Div. 2) and Enigma 2022 - Cybros LNMIIT
// URL: https://codeforces.com/contest/1763/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define IOS  ios::sync_with_stdio(false);
#define CIT  cin.tie(0);
#define COT  cout.tie(0);
#define pii pair<int,int>
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


ll n,k;
pii a[N];
multiset<pii> s;
bool cmp(pii a,pii b){
	return a.y < b.y;
}
void solve(){
	s.clear();
	
	cin>>n>>k;
	
	Fup(i,1,n) cin>>a[i].y;
	Fup(i,1,n) cin>>a[i].x;
	
	sort(a+1,a+1+n,cmp);
	
	Fup(i,1,n) s.insert(a[i]);
	
	ll total = 0 ;
	ll pos =  1  ;
	
	while(!s.empty() &&  k > 0){
		total += k ;
		while(pos <= n && total >= a[pos].y){
			s.erase(s.find(a[pos]));
			pos ++ ;
		}
		
		if(!s.empty()){
			// pii *it = s.begin();
			// k-= it.x;
			k-= s.begin()->first;
			// k -= t.x;
		}
	}
	// cout<<k<<endl;
	// k  < 0
	if(k > 0) YES
	else NO
}

signed main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
