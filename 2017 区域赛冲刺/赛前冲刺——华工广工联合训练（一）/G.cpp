#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1e5 + 5;
map<int, int> mp[maxn];
int n, m;
int node[3 * maxn];
int problem[maxn];
int solve[maxn];
int penalty[maxn];

void build(int root, int l, int r) {
    if(l == r) {
        if(l == 0) node[root] = n;
        else node[root] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(root << 1, l, mid);
    build((root << 1) + 1, mid + 1, r);
    node[root] = node[root << 1] + node[(root << 1) + 1];
}

void update(int root, int l, int r, int index, int val) {
    if(r < index || l > index) return;
    if(l == r) {
        node[root] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(root << 1, l, mid, index, val);
    update((root << 1) + 1, mid + 1, r, index, val);
    node[root] = node[root << 1] + node[(root << 1) + 1];
    //printf("l = %d, r = %d, val = %d\n", l, r, node[root]);
}

int query(int root, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return node[root];
    int mid = (l + r) / 2;
    return query(root << 1, l, mid, ql, qr) + query((root << 1) + 1, mid + 1, r, ql, qr);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        mem(problem, 0);
        problem[0] = n;
        for(int i = 0; i <= m; ++i) mp[i].clear();
        for(int i = 1; i <= n; ++i) mp[0][i] = 0;
        mem(solve, 0);
        mem(penalty, 0);
        build(1, 0, m);
        int temp = 0;
        for(int i = 1; i <= m; ++i) {
            int u, w;
            scanf("%d%d", &u, &w);
            update(1, 0, m, solve[u], -1);
            if(solve[u] == solve[1] && penalty[u] < penalty[1]) temp--;
            else if(solve[u] == solve[1] - 1 && penalty[u] + w < penalty[1]) temp++;
            mp[solve[u]].erase(u);
            solve[u]++;
            penalty[u] += w;
            mp[solve[u]][u] = penalty[u];
            update(1, 0, m, solve[u], 1);
            int res = query(1, 0, m, solve[1] + 1, m) + 1;
            if(u != 1) {
                res += temp;
            }
            else {
                temp = 0;
                map<int, int>::iterator it;
                for(it = mp[solve[1]].begin(); it != mp[solve[1]].end(); ++it) {
                    if(it->second < penalty[1]) {
                        temp++;
                    }
                }
                res += temp;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
