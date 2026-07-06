#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;
 
int head, e[N], ne[N], idx ;

void init() {
    head = -1;
    idx = 0;
}
// 插入顺序是 1，2，3 但是遍历顺序是 3 ，2，1
void add_to_head(int x) {
    e[idx] = x ; 
    ne[idx] = head ; 
    head = idx ++ ;
}

void add(int k,int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++ ;
}



int main() {
    int n;cin>>n;
  
    return 0;
}