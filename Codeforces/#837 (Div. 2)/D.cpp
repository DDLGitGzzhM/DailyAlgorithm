// Problem: D. Hossam and (sub-)palindromic tree
// Contest: Codeforces - Codeforces Round #837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/D
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


const int N = 2e3+10,INF = 0x3f3f3f3f;
const double eps = 1e-5;


struct node{
    int to,val;
};


int dp[N][N], nxt[N][N];
int n;
vector<int>g[N];
string s;
void dfs(int u, int fa, int to) {
    nxt[u][to] = fa;
    for (int v : g[u]) {
        if (v == fa)continue;
        dfs(v, u, to);
    }
}
 
int cal(int u, int v) {
    if (u == v)return 1;
    if (nxt[u][v] == v) {
        if (s[u] == s[v])return 2;
        else return 1;
    }
    if (dp[u][v] != -1)return dp[u][v];
    int res = 0;
    res = max(cal(nxt[u][v], v), cal(u, nxt[v][u]));
    if (s[u] == s[v])
        res = max(res, cal(nxt[u][v], nxt[v][u]) + 2);
    return dp[u][v] = res;
}
void solve() {
    cin >> n;
    //初始化
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)dp[i][j] = -1, nxt[i][j] = 0;
    for (int i = 1; i <= n; i++)g[i].clear();
 
    cin >> s;
    s = "?" + s;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)dfs(i, 0, i);
    int ans = 0;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)
        ans = max(ans, cal(i, j));
    cout << ans << endl;
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
