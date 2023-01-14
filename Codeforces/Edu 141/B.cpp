// Problem: B. Matrix of Differences
// Contest: Codeforces - Educational Codeforces Round 141 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1783/problem/B
// Memory Limit: 256 MB
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


int a[N];
int b[100][100];

void solve(){
	int n;cin>>n;
	if(n == 2){
		cout<<"1 3"<<endl;
		cout<<"4 2"<<endl;
		return;
	}
	int maxn = 1;
	int minn = n*n ;

	int flag = 1;
// 	
	// if(n%2 == 0 ){
		// int op = 0  ;
// 		
		// Fup(i,1,n){
			// if(i%2== 0) op = 1;
			// else op = 0 ;
// 			
			// Fup(j,1,n){
				// if(op == 0){
					// if(flag) b[i][j] = (minn -- ) , flag = 0;
					// else b[i][j] = (maxn ++ ) , flag = 1;
				// }else{
					// if(flag) b[i][j] = (maxn ++ ) , flag = 0;
					// else  b[i][j] = (minn -- ) , flag = 1;
				// }
			// }
		// }
// 		
// 			
// 				
		// Fup(i,1,n){
			// // if(i%2 == 0){
				// // Fup(j,1,n) cout<<b[i][j]<<" ";
				// // cout<<endl;
// // 				
				// // continue;
			// // }
			// // Fup(j,1,n){
				// // cout<<b[i][j]<<" ";
				// // if(j+4 <= n) swap(b[i][j],b[i][j+4]);
			// // }
			// Fup(j,1,n) cout<<b[i][j]<<" ";
			// cout<<endl;
// 			
			// // if(i%2 == 1){
			// // Fup(j,1,n){
				// // cout<<b[i][j]<<" ";
			// // }
			// // }else{
				// // Fup(j,n/2+1,n) cout<<b[i][j]<<" ";
				// // Fup(j,1,n/2) cout<<b[i][j]<<" ";
			// // }
			// // cout<<endl;
// 			
		// }
		// return;
	// }
	Fup(i,1,n){
		Fup(j,1,n){
			if(flag){
				b[i][j] = (minn -- );
				flag = 0 ;
			}else{
				b[i][j] = (maxn ++ );
				flag = 1;
			}
		}
	}
	
	Fup(i,1,n){
		if(i%2 == 1){
				Fup(j,1,n){
			cout<<b[i][j]<<" ";
		}	
		}else{
			Fde(j,n,1) cout<<b[i][j]<<" ";
		}
		cout<<endl;
		
	}
}

int main(){
	int t;cin>>t;while(t--)
    solve();
    return 0 ;
}
