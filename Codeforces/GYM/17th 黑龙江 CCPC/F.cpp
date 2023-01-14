// Problem: F. 342 and Xiangqi
// Contest: Codeforces - The 17th Heilongjiang Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103688/problem/F
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


const int N = 10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};



int dis[N][N];

void solve(){
	int a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	
	memset(dis,0x3f,sizeof dis);
	Fup(i,1,7) dis[i][i] = 0 ;
	
	dis[1][2] = dis[1][3] = 1;
	dis[2][1] = dis[2][4] = 1;
	dis[3][1] = dis[3][4] = 1;
	dis[4][2] = dis[4][3] = dis[4][5] = dis[4][6] = 1;
	dis[5][4] = dis[5][7] = 1;
	dis[6][4] = dis[6][7] = 1;
	dis[7][5] = dis[7][6] = 1;
	
	Fup(k,1,7){
		Fup(i,1,7){
			Fup(j,1,7){
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	
	int ans = min(dis[a1][b1] + dis[a2][b2] , dis[a1][b2]+dis[a2][b1]);
	cout<<ans<<endl;
	
	
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
