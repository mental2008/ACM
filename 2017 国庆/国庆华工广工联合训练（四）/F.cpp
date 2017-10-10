#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 100005;
int n;
int r[maxn];
int rnk[maxn];
LL a[maxn];
LL val[maxn];
vector<int> G[maxn];
int dfs_clock;
int in[maxn];
int out[maxn];

void dfs(int u, int fa) {
    in[u] = ++dfs_clock;
    val[dfs_clock] = a[u];
    rnk[dfs_clock] = r[u];
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
    }
    out[u] = dfs_clock;
}

struct Point {
    LL value;
    int rank;
    LL sum;
    Point(LL _value, int _rank) {
        value = _value, rank = _rank;
        sum = 0;
    }
    bool operator < (const Point &e) const {
        return rank < e.rank;
    }
};

struct Node {
    vector<Point> vec;
} node[maxn * 3];

void build(int root, int l, int r) {
    if(l == r) {
        node[root].vec.push_back((Point){val[l], rnk[l]});
        node[root].vec[0].sum = val[l];
        return;
    }
    for(int i = l; i <= r; ++i) {
        node[root].vec.push_back((Point){val[i], rnk[i]});
    }
    sort(node[root].vec.begin(), node[root].vec.end());
    LL res = 0;
    for(int i = l; i <= r; ++i) {
        res += node[root].vec[i - l].value;
        node[root].vec[i - l].sum = res;
    }
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
}

LL query(int root, int l, int r, int ql, int qr, int limit) {
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) {
        vector<Point>::iterator it = lower_bound(
            node[root].vec.begin(), node[root].vec.end(), (Point){0, limit}
        );
        if(it == node[root].vec.begin())
            return 0;
        else
            it--;
        return it->sum;
    }
    int mid = (l + r) / 2;
    return (
        query(root * 2, l, mid, ql, qr, limit) +
        query(root * 2 + 1, mid + 1, r, ql, qr, limit)
    );
}

int main() {
    scanf("%d", &n);
    int root;
    mem(in, 0);
    mem(out, 0);
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i) {
        int u;
        scanf("%d%d%d", &u, &r[i], &a[i]);
        if(u == -1) {
            root = i;
        }
        else {
            G[u].push_back(i);
            G[i].push_back(u);
        }
    }
    dfs_clock = 0;
    dfs(root, -1);
    build(1, 1, n);
    for(int i = 1; i <= n; ++i) {
        LL ans;
        if(in[i] + 1 > out[i]) ans = 0;
        else ans = query(1, 1, n, in[i] + 1, out[i], r[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
