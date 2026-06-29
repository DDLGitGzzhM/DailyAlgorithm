#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int q[N], n , temp[N] ;

void merge_sort(int q[], int l, int r) {
	if(l >= r) return ;
	int mid = (l + r) >> 1; 
	merge_sort(q,l,mid) , merge_sort(q,mid + 1, r) ;
	
	int k = 0 , i = l , j = mid + 1;  

	while(i <= mid && j <= r) {
		if(q[i] <= q[j]) temp[++k] = q[i ++ ] ;
		else temp[++k] = q[j ++ ];
	}
	while(i <= mid) temp[++k] = q[i ++ ];
	while(j <= r) temp[++k] = q[j ++] ;
	
	for(int i = l , j = 1 ;  i <= r ; i ++ , j ++ ) q[i] = temp[j];
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
    merge_sort(q,1,n);
    for(int i = 1; i <= n ; i ++ ) cout <<q[i] << " ";
	return 0;
}
