// Problem: C. Elemental Decompress
// Contest: Codeforces - Codeforces Round #842 (Div. 2)
// URL: https://codeforces.com/contest/1768/problem/C
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


int cnt[N];
int a[N];
int p[N],q[N];

void solve(){
	int n;cin>>n;
	Fup(i,1,n) cnt[i] = 0 ;
	Fup(i,1,n){
		cin>>a[i];
		cnt[a[i]] ++ ;
	}
	
	int total = 0  ;
	//一开始最多有n次
	
	Fup(i,1,n){
		if(cnt[i] == 1) total ++ ;
		else if(cnt[i] + total  > 2 ){
			NO
			return;
		}
	}
	YES
	map<int,int> mp , st;
	
	vector<int> vs,ts;
	Fup(i,1,n) if(!cnt[i]) vs.pb(i);
	Fup(i,1,n) if(cnt[i] > 1) ts.pb(i);
	
	for(int i =  0 ; i < ts.size() ;i ++ ){
		mp[ts[i]] = vs[i];
		
	}
	// int idx  =  0 ;
	
	
	Fup(i,1,n){

		if(cnt[a[i]] == 1) p[i] = q[i] = a[i];
		else{

			if(st[a[i]] == 0){
				p[i] = a[i];
				q[i] = mp[a[i]];
				st[a[i]] = 1;
				
			}else{
				p[i] = mp[a[i]] ;
				
				// cout<<"vs: "<<vs[mp[a[i]]]<<endl;
				
				q[i] = a[i];
			}
		}
	}
	
	Fup(i,1,n) cout<<p[i]<<" ";
	cout<<endl;
	
	Fup(i,1,n) cout<<q[i]<<" ";
	cout<<endl;
	
}

int main(){
	IOS
	CIT
	COT
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
