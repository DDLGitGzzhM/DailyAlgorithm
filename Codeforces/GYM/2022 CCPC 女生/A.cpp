// Problem: A. 减肥计划
// Contest: Codeforces - 2022年中国大学生程序设计竞赛女生专场
// URL: https://codeforces.com/gym/104081/problem/A
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
#define pii pair<int,int>
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




ll n,k;
pii maxn ; 
pii a[N];

void solve(){
	cin>>n>>k;
	
	Fup(i,1,n){
		cin>>a[i].x;
		a[i].y = i ;
		
		if(maxn.x < a[i].x){
			maxn.y = a[i].y;
			maxn.x = a[i].x;
		}
	}
	
	if(k >= n - 1) cout<<maxn.y<<endl;
	else{
		int cnt = 1;
		int pos = 1;
		
		Fup(i,2,maxn.y){
			if(cnt == k){
				cout<<pos<<endl;
				return;
			}
			if(a[pos].x >= a[i].x) cnt ++ ;
			else{
				cnt = 1;
				pos = i;
			}	
			// cout<<a[pos].x<<" "<<cnt<<endl;
	
		}
		
		cout<<maxn.y<<endl;
		
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
