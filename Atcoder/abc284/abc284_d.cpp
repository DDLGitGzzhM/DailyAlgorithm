// Problem: D - Happy New Year 2023
// Contest: AtCoder - AtCoder Beginner Contest 284
// URL: https://atcoder.jp/contests/abc284/tasks/abc284_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define IOS  ios::sync_with_stdio(false);
#define CIT  cin.tie(0);
#define COT  cout.tie(0);

#define ll unsigned long long
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


const int N = 2e7+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};



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

bool is_prime(ll x)
{
    if (x < 2) return false;
    for (ll i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

ll n ;

void solve(){
	cin>>n;
	
	Fup(i,0,cnt-1){
		Fup(j,0,cnt-1){
			if(i == j) continue;
			ll x = primes[i] ;
			ll y = primes[j] ;

			if(x*x*y == n){ cout<<x<<" "<<y<<endl;return;}
			else if(y*y*x == n) {cout<<y<<" "<<x<<endl;return;}
			
		}
			// ll x = primes[i];
// 			
			// if(n % (1ll*x*x) != 0 ) continue;
// 			
			// ll y = n / (1ll*x*x);
// 			
			// if(is_prime(y)){
				// cout<<x<<" "<<y<<endl;
				// return;
			// }
// 			
			// y = n / x;
			// y = sqrtl(y);
// 			
			// if(y*y*x == n && is_prime(y)){
				// cout<<x<<" "<<y<<endl;
				// return;
			// }
	}
}

int main(){
	IOS
	CIT
	COT
	
	get_primes(1e6);
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
