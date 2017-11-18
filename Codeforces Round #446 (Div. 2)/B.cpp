#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
int n;
struct Edge {
    int l, r;
    bool operator < (const Edge& e) const {
        if(l == e.l) return r > e.r;
        else return l < e.l;
    }
} edges[maxn];
int main() {
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int L;
        scanf("%d", &L);
        if(L == 0 || i == 1) continue;
        else {
            int l = max(1, i - L);
            int r = i - 1;
            edges[cnt].l = l;
            edges[cnt++].r = r;
        }
    }
    sort(edges, edges + cnt);
    int sum = 0;
    int now = 1;
    for(int i = 0; i < cnt; ++i) {
        // printf("%d %d\n", edges[i].l, edges[i].r);
        if(edges[i].r < now) continue;
        if(edges[i].l > now) {
            sum += (edges[i].l - now);
            now = edges[i].r + 1;
        }
        else if(now <= edges[i].r) now = edges[i].r + 1;
    }
    sum += (n - now + 1);
    printf("%d\n", sum);
    return 0;
}
