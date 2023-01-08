// Problem: 手动计算
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/17148/L
// Memory Limit: 1048576 MB
// Time Limit: 6000 ms
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
const double eps = 1e-2;


struct node{
    int to,val;
};




double a1,b1,a2,b2;
double cnt ;

void solve(){
	cnt = 0 ;
	
	cin>>a1>>b1>>a2>>b2;
	for(double i =  -8; i <= 8 ; i += 0.01){
		for(double j = -8 ; j <= 8 ;j += 0.01){
			if(i*i/a1/a1 + j*j/b1/b1 <=1 || i*i/a2/a2 + j*j/b2/b2 <= 1){
						cnt ++ ;	
			}
		}
	}
	
	cnt = (cnt*16*16/(1600*1600));//面积之比
	printf("%.1f\n" , cnt);
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
