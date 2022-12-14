// Problem: A. Extremely Round
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/0?f0a28=1
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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


const int N = 1e6+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};




ll a[N];

bool check(int x){
	int cnt = 0 ;
	while(x!=0){
		if(x%10) ++ cnt;
		x/=10;
	}
	if(cnt >= 2) return false;
	return true;
}

void get(int x){
	Fup(i,1,x){
		if(check(i)) a[i] = a[i-1] + 1;
		else a[i] = a[i-1];	
	}
}
void solve(){
	int n;cin>>n;
	cout<<a[n]<<endl;
}

int main(){
	get(999999);
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
