// Problem: B. Doremy's Perfect Math Class
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <math.h>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
#define IOS  ios::sync_with_stdio(false);
#define CIT  cin.tie(0);
#define COT  cout.tie(0);

#define ll long long
#define x first
#define y second
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(),x.end()
#define Fup(i,a,b) for(int i=a;i<=b;i++)
#define Fde(i,a,b) for(int i=a;i>=b;i--)
#define NO cout<<"NO"<<endl;
#define YES cout<<"YES"<<endl;
#define cer(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<" "<<endl
typedef priority_queue<int,vector<int>,greater<int>>  Pri_m;
typedef pair<int,int> pii;
typedef vector<int> VI;
map<int,int> mp;
const int N = 2e5+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};



ll a[N];

void solve(){
	ll ans = 0 ;
	int n;cin>>n;
	
	Fup(i,1,n){
		cin>>a[i];
		ans = __gcd(ans,a[i]);
	}
	cout<<a[n]/ans<<endl;
	
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
