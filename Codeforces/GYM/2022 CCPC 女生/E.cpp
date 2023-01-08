// Problem: E. 睡觉
// Contest: Codeforces - 2022年中国大学生程序设计竞赛女生专场
// URL: https://codeforces.com/gym/104081/problem/E
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


int x,t,k,n,d;
int a[N];
// int t[N];

void solve(){
	cin>>x>>t>>k>>n>>d;
	
	ll sum = 0 ;
	
	Fup(i,1,n){
		cin>>a[i];
		if(a[i] > d) a[i] =  1;
		else a[i] = -1;
		sum += a[i];
	}
	
	if(sum < 0) YES
	else{
		
		Fup(i,n+1,2*n) a[i] = a[i-n];
		
		ll cnt = 0  ;
		
		Fup(i,1,2*n){
			x += a[i];
			if(cnt == t){
				YES
				return;
			}
			
			if(x <= k) cnt ++ ;
			else cnt = 0 ;
		}
		
		if(cnt == 2*n) YES
		else NO
	}
	
}

int main(){
	IOS
	CIT
	COT
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
