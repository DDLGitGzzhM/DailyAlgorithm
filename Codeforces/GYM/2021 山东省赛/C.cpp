// Problem: C. Cat Virus
// Contest: Codeforces - 2021 Shandong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103118/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
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




ll k;

vector<int> g[N];

int cnt;

void dfs(int u,ll val){
	 //当前层要一个节点
	 ll temp = val - 1;
	 
	 //如果可以整除那就再这层继续分
	 if(temp%2 == 0){
	 	while(temp%2 == 0 && temp){
	 		temp/= 2;
	 		g[u].pb(++cnt);
	 	}
	 }

	 // if(temp == 0) return ;
	 	 
	 if(temp == 1) return;
	 //全白 不进行染色
	 
	 g[u].pb(++cnt);//开辟下一个节点
	 
	 dfs(cnt,temp);
	 	
}
void solve(){
	cin>>k;
	cnt = 1;
	dfs(1,k);
	cout<<cnt<<endl;
	
	Fup(i,1,cnt){
		for(auto x : g[i]){
			cout<<i<<" "<<x<<endl;
		}
	}
}

signed main(){
	IOS
	CIT
	COT
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
