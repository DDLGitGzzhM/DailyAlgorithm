// Problem: P2949 [USACO09OPEN]Work Scheduling G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2949
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define IOS  ios::sync_with_stdio(false);
#define CIT  cin.tie(0);
#define COT  cout.tie(0);
#define int unsigned long long
#define ll long long
#define x first
#define y second
#define pb push_back
#define endl '\n'
#define pii pair<int,int>
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
vector<pii> v;

void solve(){
	cin>>n;
	
	Fup(i,1,n){
		int a,b;cin>>a>>b;
		v.pb({a,b});
	}
	sort(all(v));
	
	priority_queue<int,vector<int>,greater<int>> heap;
	
	int time = 1;
	int ans = 0 ;
	
	for(auto [x,y] : v){

		//时间不够的时候 考虑将前面加的小的替换
		if(time > x){
			auto t = heap.top();
			
			if(t < y){
				heap.pop();
				heap.push(y);
				ans += y - t;//加上当前的 减去最小的
			}
			
		}else{
			heap.push(y);
			ans += y;
			time ++ ;
			
		}//如果时间够的话
	}
	
	cout<<ans<<endl;
	
	
	
}

signed main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
