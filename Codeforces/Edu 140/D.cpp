// Problem: D. Playoff
// Contest: Codeforces - Educational Codeforces Round 140 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1767/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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




string s;
int c0,c1;

void solve(){
	int n;
	cin>>n;
	cin>>s;
	// cout<<s<<endl;
	
	for(auto x : s)if(x == '1') c1 ++ ;
	c0 = n - c1;
	// cout<<c1<<" "<<c0<<endl;
	
	int minn = pow(2 , c1);
	int maxn = pow(2 , n)  - pow(2 , c0) +1;
	
	// cout<<minn<<" "<<maxn<<endl;
	
	Fup(i,minn,maxn) cout<<i<<" ";
	cout<<endl;
	
}

int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
