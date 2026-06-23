#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int q[N], n ;

void quick_sort(int q[],int l , int r) {
    if (l >= r)  return ;
    int x = q[(l + r ) >> 1] , i = l - 1 , j = r  + 1 ;
    while(i <  j) {
        do i ++ ; while(q[i] < x) ;
        do j -- ; while(q[j] > x) ;
        if (i < j ) swap(q[i],q[j]);
    }
    quick_sort(q,l,  j);
    quick_sort(q, j + 1  , r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 使用 gzm-call cpp check <本文件> 时会自动从 io_cases 读入 .in 并比对 .out。
	// 本地自测可取消注释并调整路径（相对源文件所在目录运行时，常用 io_cases/...）：
	// freopen("io_cases/example.in", "r", stdin);
	// freopen("io_cases/example.out", "w", stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++ ) cin >> q[i];
    quick_sort(q,1,n);
    for(int i = 1; i <= n ; i ++ ) cout <<q[i] << " ";
	return 0;
}
