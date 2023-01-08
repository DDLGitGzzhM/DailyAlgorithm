// Problem: C. Another Array Problem
// Contest: Codeforces - Codeforces Round #840 (Div. 2) and Enigma 2022 - Cybros LNMIIT
// URL: https://codeforces.com/contest/1763/problem/C
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



ll a[N],sum;
int n;
void solve(){
	cin>>n;
	
	sum = 0;
	
	Fup(i,1,n) cin>>a[i] , sum += a[i];
	// sort(a+1,a+1+n);
	
	if(n == 2){
		sort(a+1,a+1+n);
		cout<<max(sum ,2ll*(a[2] - a[1]))<<endl;
		return;
	}// 2 | 3... | 3
	
	if(n == 3){
		ll res = 0 ;
		res = max(res , 3ll * abs(a[2] - a[1]));
		res = max(res , 3ll * abs(a[3] - a[1]));
		res = max(res , 3ll * abs(a[3] - a[2]));
		// cout<<res<<endl;
		res = max(res , 2ll * abs(a[2] - a[1]) + a[3]);
		res = max(res , 2ll * abs(a[3] - a[2]) + a[1]);
		res = max(res , 2ll * abs(a[3] - a[1]) + a[2]);
		// cout<<res<<endl;
		
		// res = max(res , 2ll * (a[3] - a[1])) + a[2];
		
		res = max(res , 3*a[3]);
		// res = max(res , 3*a[2]);
		res = max(res , 3*a[1]);
		res = max(res , sum);
		
		cout<<res<<endl;
		return;
	}
	
	sort(a+1,a+1+n);
	cout<<max(sum , 1ll*n*a[n])<<endl;
	
	
	
	
	
	
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
