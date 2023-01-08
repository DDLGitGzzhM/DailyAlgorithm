// Problem: 牛牛取石子
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/49888/D
// Memory Limit: 524288 MB
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


void solve(){
	ll n,m;cin>>n>>m;
	ll minn ;
	
	minn = min(n , m);
	
	if(minn <= 2){
		cout<<"niuniu"<<endl;
		return;
	}

	if(minn % 3 == 2) cout<<"niuniu"<<endl;
	else cout<<"niumei"<<endl;
	// if( (minn + 1)/2  %2 == 0) cout<<"niumei"<<endl;
	// else cout<<"niuniu"<<endl;
	
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
