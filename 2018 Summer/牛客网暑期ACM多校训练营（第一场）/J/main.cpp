#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, q;
int a[maxn];
struct Node {
    int l, r;
    int block;
    int index;
    bool operator < (const Node &e) const {
        if(block == e.block) return r < e.r;
        return block < e.block;
    }
} node[maxn];
int vis[maxn];
int ans[maxn];

int main()
{
    while(~scanf("%d%d", &n, &q)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        int Magic = sqrt(n);
        for(int i = 1; i <= q; ++i) {
            scanf("%d%d", &node[i].l, &node[i].r);
            node[i].index = i;
            node[i].block = node[i].l / Magic;
        }
        sort(node + 1, node + 1 + q);
        int ql, qr;
        ql = 0;
        qr = 0;
        int res = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; ++i) {
            vis[a[i]]++;
            if(vis[a[i]] == 1) res++;
        }
        for(int i = 1; i <= q; ++i) {
            while(qr < node[i].r) {
                vis[a[qr]]--;
                if(vis[a[qr]] == 0) res--;
                qr++;
            }
            while(ql > node[i].l) {
                vis[a[ql]]--;
                if(vis[a[ql]] == 0) res--;
                ql--;
            }
            while(qr > node[i].r) {
                qr--;
                vis[a[qr]]++;
                if(vis[a[qr]] == 1) res++;
            }
            while(ql < node[i].l) {
                ql++;
                vis[a[ql]]++;
                if(vis[a[ql]] == 1) res++;
            }
            ans[node[i].index] = res;
        }
        for(int i = 1; i <= q; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
