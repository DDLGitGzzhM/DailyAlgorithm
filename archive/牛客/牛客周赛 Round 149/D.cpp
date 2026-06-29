#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 2e5 + 10; 
const LL mod = 998244353;
int n;
LL a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    LL s = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    
    int l = 1;
    LL current = 0; 
    
    // 初始化：由于空数组和为 0 也是一种合法选择，初始差值就是 |0 - s|
    LL best_sum = 0;
    LL min_diff = abs(0 - s); 
    
    for(int r = 1; r <= n; r++) {
        current += a[r]; 
        
        // 1. 刚加完数，尝试更新最优解
        LL current_diff = abs(current * 2 - s);
        if(current_diff < min_diff) {
            min_diff = current_diff;
            best_sum = current;
        }
        
        // 当窗口和大于一半时，左指针收缩
        while(current * 2 > s && l <= r) {
            current -= a[l];
            l++;
            
            // 2. 减完数，立刻尝试更新最优解（解决吐光或变小时没记录到的问题）
            current_diff = abs(current * 2 - s);
            if(current_diff < min_diff) {
                min_diff = current_diff;
                best_sum = current;
            }
        }
    }
    
    // 最终计算乘积并取模
    LL ans = (best_sum % mod) * ((s - best_sum) % mod) % mod;
    cout << ans << "\n";
    
    return 0;
}