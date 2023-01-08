// Problem: H. Adventurer's Guild
// Contest: Codeforces - 2021 Shandong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103118/problem/H
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


const int N = 1e3+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};




int n,H,S;
int h[N],s[N],w[N];
ll f[N][N];

void solve(){
	cin>>n>>H>>S;
	Fup(i,1,n) cin>>h[i]>>s[i]>>w[i];
	Fup(i,1,n){
		Fde(j,H,h[i]+1){
			Fde(k,S,0){
				//消耗
				if(k < s[i] && j+k > s[i] + h[i]){
					chmax(f[j][k] , f[j - h[i] - (s[i] - k)][0]+w[i]);
				}else if(k >= s[i]){
					chmax(f[j][k],  f[j-h[i]][k-s[i]] + w[i]);
				}
			}
		}
	}
	cout<<f[H][S]<<endl;

}

int main(){
	IOS
	CIT
	COT
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
