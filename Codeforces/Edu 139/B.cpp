// Problem: B. Notepad#
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/B
// Memory Limit: 256 MB
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


map<int,int> mp;


int n;
string s;
void solve(){
	mp.clear();
	
	cin>>n;
	
	cin>>s; s = ' ' + s;
	
	
	int len = s.size();

	int flag = 0 ;
	
	Fup(i,1,len){
		mp[s[i]] ++ ;
		if(mp[s[i]] == 1) flag = 1;
	}
	
	if(flag == n){
		NO
		return;
	}
	
	for(int i = 3 ; i <= len - 1 ;i ++ ){
		for(int j  = 1 ; j  + 1 < i  ; j ++ ){
			if(s[i] == s[j] && s[i+1] == s[j+1]){
				YES
				return;
			}
		}
	}
	
	NO
}

int main(){
	IOS
	CIT
	COT
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
