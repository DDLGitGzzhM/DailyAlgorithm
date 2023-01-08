// Problem: 甜甜圈
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/17148/J
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
#define pii pair<int,int>
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



ll c[N];
int n,m;
int lowbit(int x){return x&(-x);}

void updata(int i,int k)     
{
    while(i <= n + m) 
    {
        c[i] += k;
        i += lowbit(i); 
    }
}
ll getsum(int i){        
    ll res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i); 
    }
    return res;
}

pii a[N];
bool cmp(pii a,pii b){
	return a.x > b.x ;
}
void solve(){
	
	cin>>n>>m;
	
	
	for(int i = n ; i >= 1 ;i --  ){
		updata(i,1);
		cin>>a[i].x ;
		a[i].y = i ;
	}
	
	for(int i = n+1 ; i <= n + m ;i ++ ){
		updata(i,1);
		cin>>a[i].x;
		a[i].y = i ;
	}
	
	ll ans = 0 ;
	
	a[0].y = n;
	
	sort(a+1,a+1+n+m,cmp);
	
	for(int i = 1; i <= n  + m ;i ++ ){
		updata(a[i].y , -1);
		ans += abs(getsum(a[i].y) - getsum(a[i-1].y));
	}
	
	cout<<ans<<endl;
	
}

int main(){
	// int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
