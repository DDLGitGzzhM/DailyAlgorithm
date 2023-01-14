// Problem: H. Kanbun
// Contest: Codeforces - The 17th Heilongjiang Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103688/problem/H
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


struct node{
    int to,val;
};




int nxt[N];
stack<int> stk;
int n;
string s;

void dfs(int l,int r){
	if(l > r) return; 
	if(l == r){
		cout<<l<<" ";
		
		return;
	}
	
	Fup(i,l,r){
		if(s[i] == '-') cout<<i<<" ";
		else if(s[i] == ')') cout<<i<<" ";
		else{
			//找 下一个并且是j - 1
			//然后继续找
			dfs(i+1 , nxt[i] - 1) ;
			cout<<nxt[i]<<" ";
			cout<<i<<" ";//最后再输出外围的
			i = nxt[i];//移动
		}
	}
}
void solve(){
	cin>>n;
	cin>>s;s = " " + s;
	Fup(i,1,n){
		if(s[i] == '(') stk.push(i);
		else  if(s[i] ==')'){
			if(!stk.empty()){
				nxt[stk.top()] = i ;
				stk.pop();
			}
		}
	}
	dfs(1,n);
}

int main(){
	//int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
