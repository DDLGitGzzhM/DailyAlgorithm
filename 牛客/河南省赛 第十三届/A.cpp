// Problem: 祝融传火
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/50233/A
// Memory Limit: 524288 MB
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


const int N = 1e3+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};




int n,m;
int a[N][N];

void solve(){
	cin>>n>>m;

	Fup(i,1,n)
		Fup(j,1,m)
		cin>>a[i][j];
	
	int H,W;cin>>H>>W;
	
	
	Fup(i,1,n){
		Fup(j,1,m){
			int d1 = i + H - 1;
			if(d1 <= 0 || d1 > n) continue;
			int d2 = j + W - 1;
			if(d2 <= 0 || d2 > m) continue;
			
			if(a[i][j] == a[d1][j] && a[i][j] == a[i][d2] && a[i][j] == a[d1][d2]){
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
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
