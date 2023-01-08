// Problem: A. Cut the Triangle
// Contest: Codeforces - Educational Codeforces Round 140 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1767/problem/A
// Memory Limit: 512 MB
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




int a[N],b[N];

void solve(){
	Fup(i,1,3){
		cin>>a[i]>>b[i];
	}
	int f1 = 0 , f2 = 0 ;
	Fup(i,1,3){
		Fup(j,1,i-1){
			if(a[i]  == a[j]) f1 = 1;
			
		}
	}
	
	Fup(i,1,3){
		Fup(j,1,i-1){
			if(b[i]  == b[j]) f2 = 1;
			
		}
	}
	
	if(f1 && f2) NO
	else YES
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
