#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
map<LL, LL> mp;
map<LL, int> vis;
int n;
LL x, k;
struct Node {
    LL a;
    LL num;
} node[maxn];

bool cmp(Node i, Node j) {
    return i.a < j.a;
}

int main() {
    while(~scanf("%d%lld%lld", &n, &x, &k)) {
        mp.clear();
        vis.clear();
        int cnt = 1;
        for(int i = 1; i <= n; ++i) {
            LL val;
            scanf("%lld", &val);
            int index = vis[val];
            if(!index) {
                vis[val] = cnt;
                node[cnt].a = val;
                node[cnt++].num = 1LL;
            }
            else node[index].num = node[index].num + 1LL;
        }
        sort(node + 1, node + cnt, cmp);
        LL ans = 0;
        for(int i = cnt - 1; i >= 1; --i) {
            LL upp = ceil((double)node[i].a / x);
            if((k == 0 && node[i].a % x) || (k == 1 && node[i].a % x == 0)) ans += (node[i].num * node[i].num);
            ans += (mp[upp + k - 1] * node[i].num);
            LL low = node[i].a / x;
            mp[low] += node[i].num;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
