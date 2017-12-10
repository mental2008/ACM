#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 200005;
int n, k;
int cnt[maxn];
vector<int> vec;
int main() {
    while(~scanf("%d%d", &n, &k)) {
        mem(cnt, 0);
        vec.clear();
        for(int i = 1; i <= n; ++i) {
            int val;
            scanf("%d", &val);
            cnt[val]++;
        }
        for(int i = 1; i <= 200000; ++i) {
            if(cnt[i]) vec.push_back(cnt[i]);
        }
        sort(vec.begin(), vec.end());
        int len = vec.size();
        int ans = 0;
        if(len > k) {
            for(int i = 0; i < len - k; ++i) {
                ans += vec[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
