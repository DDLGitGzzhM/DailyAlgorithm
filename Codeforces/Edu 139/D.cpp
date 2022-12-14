// Problem: C. Hossam and Trainees
// Contest: Codeforces - Codeforces Round #837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/C?f0a28=1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

map<int,int> mp;


int a[N];

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

void solve(){
	mp.clear();
	int a,b;cin>>a>>b;
	
	int d = abs(a - b);
	
	int ans = INF ;
	 
	if(__gcd(a,b)  != 1){
		cout<<0<<endl;
		return;
	}
	
	for(int i =  0  ; i < cnt ; i ++ ){
		if(primes[i] > sqrt(d)) break;//不break 就会 T
		
				
		if(d%primes[i]) continue;

		while(d%primes[i] == 0) d/=primes[i];
		
		ans = min(ans,primes[i] - a%primes[i]);
		
	}
	
	if(d > 1) ans = min(ans,d-a%d);
	
	if(ans == INF) cout<<-1<<endl;
	else cout<<ans<<endl;
}

int main(){
	IOS
	CIT
	COT
	get_primes(40000);
	
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
