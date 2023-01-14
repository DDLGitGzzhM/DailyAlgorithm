// Problem: A. Make it Beautiful
// Contest: Codeforces - Educational Codeforces Round 141 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1783/problem/0
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


const int N = 2e5+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};




int a[N];
int b[N];

void solve(){
	int n;cin>>n;
	Fup(i,1,n) cin>>a[i];
	ll sum = 0  ;
	sort(a+1,a+1+n);
	b[1] = a[1] , b[2] = a[n];
	int j = 2;
	
	Fup(i,3,n) b[i] = a[j++ ];
	
	Fup(i,1,n){
		if(sum == b[i]){
			NO
			return;
		}
		sum += b[i];
	}
	YES
	Fup(i,1,n){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
