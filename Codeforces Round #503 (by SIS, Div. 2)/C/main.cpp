#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3005;
const LL INF = 0x3f3f3f3f3f3f3f3f;
vector<LL> G[maxn];
vector<LL> temp;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int index;
        LL val;
        scanf("%d%lld", &index, &val);
        G[index].push_back(val);
    }
    for(int i = 1; i <= m; ++i) {
        sort(G[i].begin(), G[i].end());
    }
    LL ans = INF;
    for(int i = 1; i <= n; ++i) {
        LL res = 0;
        int cnt = (int)G[1].size();
        temp.clear();
        for(int j = 2; j <= m; ++j) {
            int len = (int)G[j].size();
            if(len < i) {
                for(int k = 0; k < len; ++k) {
                    temp.push_back(G[j][k]);
                }
                continue;
            }
            for(int k = 0; k <= len - i; ++k) {
                cnt++;
                res += G[j][k];
            }
            for(int k = len - i + 1; k < len; ++k) {
                temp.push_back(G[j][k]);
            }
        }
        // puts("fuck");
        sort(temp.begin(), temp.end());
        int len = (int)temp.size();
        for(int j = 0; j < i - cnt; ++j) {
            res += temp[j];
        }
        // puts("fuck");
        ans = min(ans, res);
        // printf("%d %lld\n", i, res);
    }
    printf("%lld\n", ans);
    return 0;
}
