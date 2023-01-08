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


const int N = 100+10,INF = 0x3f3f3f3f , mod =998244353;
const double eps = 1e-5;


struct node{
    int to,val;
};




int n;
int a[N][N];
int col[N],color;
ll dp[N], sum[N][N];


void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> a[i][j];
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (a[i][j] != 1)
                continue;
 
            color++;
            int c1 = col[i];
            int c2 = col[j];
            for (int k = 1; k <= n; k++)
                if ((c1 && col[k] == c1) || (c2 && col[k] == c2) || (k >= i && k <= j))
                    col[k] = color;
        }
    }
 
 
    for (int i = 1; i <= n + 1; i++)
        if (col[i] == 0)
            col[i] = ++color;
 
 
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len - 1 <= n + 1; i++)
        {
            int j = i + len - 1;
           
            if (a[i][j] == 2)
                sum[i][j] = 1;
            if (i == j)
                continue;
            sum[i][j] += sum[i + 1][j] + sum[i][j - 1] - sum[i + 1][j - 1];
        }
    }
 
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (sum[i - 1][j-1] == 0 && (col[j] != col[j - 1] && j > 1))
            {
                dp[j] += dp[i - 1];
                dp[j] %= mod;
            }
 
   ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (sum[i][n + 1] == 0)
            ans += dp[i];
 
    ans *= 2;
    ans %= mod;
    cout << ans << endl;
}
int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
