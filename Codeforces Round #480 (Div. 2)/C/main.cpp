#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
int p[maxn];
int vis[maxn];
int ans[maxn];
int sum[maxn];

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    memset(vis, -1, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < n; ++i) {
        if(vis[p[i]] != -1) ans[i] = vis[p[i]];
        else {
            // cout << "i = " << i << " val = " << p[i] << '\n';
            int Min = p[i];
            for(int j = 0; j < k; ++j) {
                if(p[i] - j < 0) break;
                if(vis[p[i] - j] != -1) {
                    if(sum[vis[p[i] - j]] + j <= k) {
                        // sum[vis[p[i] - j]] += (j + 1);
                        Min = vis[p[i] - j];
                    }
                    break;
                }
                Min = p[i] - j;
            }
            for(int j = 0; j < k; ++j) {
                if(p[i] - j < 0 || vis[p[i] - j] != -1) break;
                vis[p[i] - j] = Min;
                sum[Min]++;
            }
            ans[i] = vis[p[i]];
            // cout << ans[i] << '\n';
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
