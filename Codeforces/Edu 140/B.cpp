// Problem: B. Block Towers
// Contest: Codeforces - Educational Codeforces Round 140 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1767/problem/B
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



int a[N];
int b[N];
//5 1 ... 4 2... 3 3
//6 1 ... 5 2 .... 4 3 ...  3 4...
void solve(){
	int n;cin>>n;

	Fup(i,1,n){
		cin>>a[i];
		if(i!=1){
			b[i-1] =  a[i];
		}
	}
	

	sort(b+1,b+n);
	if(b[1] < a[1]) a[1] = a[1] ;
	
	else a[1] = a[1] + (b[1] - a[1] + 1)/2;
	Fup(i,2,n-1){
		if(b[i] > a[1]){
			a[1] = a[1] + (b[i] - a[1] + 1)/2;
		}
	}
	cout<<a[1]<<endl;
}

signed main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
