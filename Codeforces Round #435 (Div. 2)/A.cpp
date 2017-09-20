#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
int n, x;
map<int, int> mp;
int main() {
    while(~scanf("%d%d", &n, &x)) {
        mp.clear();
        for(int i = 0; i < n; ++i) {
            int val;
            scanf("%d", &val);
            mp[val]++;
        }
        int ans = 0;
        for(int i = 0; i <= x; ++i) {
            if(i == x) {
                ans += mp[i];
            }
            else if(!mp[i]) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
