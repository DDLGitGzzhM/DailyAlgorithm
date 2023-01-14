// Problem: 最大の和
// Contest: Virtual Judge - AtCoder
// URL: https://vjudge.net/problem/AtCoder-joi2007ho_a#author=wuyudi
// Memory Limit: 64 MB
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




ll n,k;
ll s[N];

void solve(){
	cin>>n>>k;
	
	Fup(i,1,n){
		cin>>s[i];
		s[i] = s[i] + s[i-1];
	}
	
	ll maxn = 0 ;
	Fup(i,1,n){
		if(i - k  + 1>= 1 ){
			maxn = max(maxn , s[i] - s[ i - k ]);
		}
	}
	cout<<maxn<<endl;
}

int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
