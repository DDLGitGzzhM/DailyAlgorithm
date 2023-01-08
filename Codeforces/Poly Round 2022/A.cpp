// Problem: A. Add Plus Minus Sign
// Contest: Codeforces - Polynomial Round 2022 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1774/problem/A
// Memory Limit: 256 MB
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

int n;
char pos[110];

void solve(){
	cin>>n;
	string s;cin>>s;
	int flag = 0 ;
	

	
	for(int i =0  ;i < n ; i ++ ){
		if(s[i] == '1'){
			if(flag) pos[i] = '-' ;
			else pos[i] = '+';
			flag = !flag;
		}else pos[i] = '+'; 
	}
	
	for(int i = 1 ;i < n ;i ++ ) cout<<pos[i];
	cout<<endl;
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
