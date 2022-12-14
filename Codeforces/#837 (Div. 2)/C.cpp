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

// 
// bool divide(int x)
// {
    // for (int i = 2; i <= x / i; i ++ )
        // if (x % i == 0)
        // {
            // int s = 0;
// 
            // ///计算质因数的指数
            // while (x % i == 0)
            // x /= i, s ++ ;
// 
            // // cout << i << ' ' << s << endl;
            // if(mp[i]) return true;
            // mp[i]  =  1;
//             
        // }
// 
    // ///2的情况
    // if (x > 1){
    	// if(mp[x]) return true;
    	// mp[x] = 1;
    // }
    // // cout << x << ' ' << 1 << endl;
// 
    // return false;
// }

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
	int n;cin>>n;
	Fup(i,1,n){
		cin>>a[i];
	}
	
	for(int i =  0  ; i < cnt ; i ++ ){
		int flag = 0 ;
		
		for(int  j = 1; j <= n ; j ++ ){
			if(a[j]%primes[i] == 0) flag ++ ;
			while(a[j]%primes[i] == 0){
				a[j]/=primes[i];
			}
		}
		
		if(flag >=2){
			YES
			return;
		}
		
	}
	
	Fup(i,1,n){
		if(a[i] != 1) mp[a[i]]  ++ ;
			
		if(mp[a[i]] >= 2){
				YES
				return;
		}
	}
	
	NO
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
