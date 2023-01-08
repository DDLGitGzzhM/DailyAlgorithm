// Problem: M. Matrix Problem
// Contest: Codeforces - 2021 Shandong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103118/problem/M
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


const int N = 500+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};



char a[N][N],b[N][N],c[N][N];

void solve(){
	int n,m;cin>>n>>m;
	
	Fup(i,1,n){
		Fup(j,1,m){
			cin>>c[i][j];
			a[i][j] = c[i][j];
			b[i][j] = c[i][j];
		}
	}
	
	Fup(i,1,n){
		if(i%2 == 1){
			Fup(j,1,m-1) a[i][j] = '1';
		}else a[i][1] = '1';
	}
	
	Fup(i,1,n){
		if(i%2 != 1){
			Fup(j,2,m) b[i][j] = '1';
		}else b[i][m] = '1';
	}
	
	Fup(i,1,n){
		Fup(j,1,m){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	
	Fup(i,1,n){
		Fup(j,1,m){
			cout<<b[i][j];
		}
		cout<<endl;
	}
	
	

}

int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
