// Problem: 七便士
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/50233/I
// Memory Limit: 1048576 MB
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



#define NO cout<<"No"<<endl;
#define YES cout<<"Yes"<<endl;


const int N = 2e5+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};




int nxt[9] = {-1,1,6,3,8,5,2,7,4};
void solve(){
	string s;cin>>s;
	s = " " + s;
	int cnt = 0 ;
	
	for(int i = 1 ; i < 9 ; i ++ ){
		if(s[i] == '1') cnt ++ ;
		
	}
	
	if(s[1] == '0' && s[4] == '0') cnt ++ ;
	
	Fup(i,1,8){
		if(s[nxt[i]] == '0' && s[nxt[i+1]] == '0') cnt ++ ;
	}
	
	if(cnt == 7)  YES
	else NO

}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
