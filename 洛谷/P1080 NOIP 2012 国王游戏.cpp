// Problem: P1080 [NOIP2012 提高组] 国王游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1080
// Memory Limit: 125 MB
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
    ll l,r;
}num[N];
ll price[N];

bool cmp(node x,node y){
	return max(y.r , x.l * x.r) < max(x.r , y.l*y.r);
}



void solve(){
	int n;cin>>n;
	ll a,b;cin>>a>>b;
	
	Fup(i,1,n){
		cin>>num[i].l>>num[i].r;
	}
	sort(num+1,num+1+n,cmp);
	
	ll maxn = 0 ;
	
	Fup(i,1,n){
		price[i] =  a/num[i].r;
		a = a*num[i].l;
		maxn = max(maxn,price[i]);
	}
	
	cout<<maxn<<endl;
	
}

int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
