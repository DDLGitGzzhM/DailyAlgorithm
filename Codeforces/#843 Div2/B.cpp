// Problem: B. Gardener and the Array
// Contest: Codeforces - Codeforces Round #843 (Div. 2)
// URL: https://codeforces.com/contest/1775/problem/B
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


const int N = 2e5+10,M = 1e5+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};




int n;
ll c[N];
map<int,int> mp;

void solve(){
	cin>>n;
	mp.clear();
	
	vector<vector<int>> v;
	
	
	
	Fup(i,1,n){
		int k;cin>>k;
		vector<int> temp ;
		
		Fup(j,1,k){
			int x;cin>>x;
			temp.pb(x);
			mp[x] ++ ;
		}
		v.pb(temp);
	}	
	
	Fup(i,0,n-1){
		int flag = 1;
		for(auto x : v[i]){
			if(mp[x] == 1){
				flag = 0  ;
				break;
			}
		}
		if(flag){
			YES
			return;
		}
	}
	
	NO
	return;

}

int main(){
	IOS
	CIT
	COT
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
