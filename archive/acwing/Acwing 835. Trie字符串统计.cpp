#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;

int son[N][26], n, idx ; 
int cnt[N];
char str[N];

void insert(char str[]) {
    int p = 0 ;
    for(int i = 0 ; str[i] ; i ++ ) {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx ; 
        p = son[p][u];
    }
    cnt[p] ++ ;
}

int query(char str[]) {
    int p = 0 ;
    for(int i = 0 ; str[i] ; i ++ ) {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
  cin>>n ;
  while(n -- ) {
    char op[2];
    scanf("%s%s", op, str);
    if (*op == 'I') insert(str);
    else cout<<query(str)<<endl;
  }
}
