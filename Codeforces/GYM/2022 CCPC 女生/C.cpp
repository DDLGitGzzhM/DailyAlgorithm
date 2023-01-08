// Problem: C. 测量学
// Contest: Codeforces - 2022年中国大学生程序设计竞赛女生专场
// URL: https://codeforces.com/gym/104081/problem/C
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
const double PI = acos(-1);


struct node{
    int to,val;
};




int n;
double  r,tha;

void solve(){

	cin>>n>>r>>tha;
	
	tha = min(tha , 2*PI - tha);
	
	double ans = r * tha ;
	
	Fup(i,1,n){
		double x;cin>>x;
		ans = min(ans , 2 * (r - x) + tha*x);
	}
	
	printf("%.10lf",ans);
}

int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
