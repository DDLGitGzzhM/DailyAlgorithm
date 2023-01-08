// Problem: 牛牛排队伍
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/49888/C
// Memory Limit: 524288 MB
// Time Limit: 4000 ms
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




int pre[N];
set<int> s;

void solve(){
	pre[1] = -1;
	
	int n,k ;cin>>n>>k;
	for(int i = 1;i<=n; i ++ ){
		// pre[i] = i - 1;
		s.insert(i);
		
	}
	
	while(k -- ){
		int op , x ;cin>>op>>x;
		if(op == 1){
			// pre[x+1] = pre[x];
			// pre[x] =  INF ;
			s.erase(x);
			
		}else{
			auto it = s.find(x);
			if(it == s.begin()) cout<<"0"<<endl;
			else{
				cout<<(*--it)<<endl;
			}
			// if(pre[x] == -1) cout<<0<<endl;
			// else cout<<pre[x]<<endl;
// 			
		}
	}

}

int main(){
	IOS
	CIT
	COT
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
