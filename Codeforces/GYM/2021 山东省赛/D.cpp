// Problem: D. Dyson Box
// Contest: Codeforces - 2021 Shandong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103118/problem/D
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
// #define x first
// #define y second
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
int x,y;

map<int,int> stx,sty;

void solve(){
	cin>>n;
	
	ll ansx = 0  ;
	ll ansy = 0  ;
	Fup(i,1,n){
		// cin>>x[i]>>y[i];
		cin>>x>>y;
		
		
		ansx += 4;
		ansy += 4;
		
		if(stx[x]) ansx -= 2;
		if(sty[y]) ansy -= 2;
		//上下 或者是 前后
		
		if(stx[x] < stx[x-1]) ansx -= 2;
		if(stx[x] < stx[x+1]) ansx -= 2;
		//左右
		
		if(sty[y] < sty[y-1]) ansy -= 2;
		if(sty[y] < sty[y+1]) ansy -= 2;
		//左右
		
		stx[x] ++ , sty[y] ++ ;
		cout<<ansx<<" "<<ansy<<endl;
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
