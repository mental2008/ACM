#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct Node {
    int l, r;
    bool operator < (const Node& e) const {
        if(l == e.l) return r < e.r;
        return l < e.l;
    }
} node[maxn];

int n, m;
int ans[maxn];

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d", &node[i].l, &node[i].r);
        }
        sort(node + 1, node + 1 + m);
        memset(ans, -1, sizeof(ans));
        for(int i = 1; i <= node[1].l; ++i) {
            ans[i] = 1;
        }
        for(int i = 1; i <= m; ++i) {
            int pos = node[i].l;
            int ql = node[i].l, qr = node[i].r;
            while(ql <= qr) {
                int mid = (ql + qr) >> 1;
                if(ans[mid] == -1) {
                    qr = mid - 1;
                }
                else {
                    pos = mid;
                    ql = mid + 1;
                }
            }
            if(ans[pos] == -1) {
                int res = 1;
                for(int j = pos; j <= node[i].r; ++j) {
                    ans[j] = res;
                    res++;
                }
            }
            else {
                int res = ans[pos] + 1;
                for(int j = pos + 1; j <= node[i].r; ++j) {
                    ans[j] = res;
                    res++;
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(ans[i] == -1) ans[i] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
        }
    }
    return 0;
}
