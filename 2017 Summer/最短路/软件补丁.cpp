#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1e14;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = (1 << 20) + 5;
int n, m;
char s1[105][25];
char s2[105][25];
LL d[maxn];
bool done[maxn];
int sum;
LL val[105];

struct HeapNode {
	LL d;
    int u;
	bool operator < (const HeapNode &e) const {
		return d > e.d;
	}
};

void dijkstra() {
	priority_queue<HeapNode> q;
    for(int i = 1; i <= sum; ++i) d[i] = INF;
    d[0] = 0;
	mem(done, 0);
	q.push((HeapNode){0, 0});
	while(!q.empty()) {
		HeapNode x = q.top();
		q.pop();
		int u = x.u;
		if(done[u]) continue;
		done[u] = 1;
		for(int i = 0; i < m; ++i) {
            bool ok = true;
            for(int j = 0; j < n; ++j) {
                if(s1[i][n - 1 - j] == '+' && (u >> j & 1)) {
                    ok = false;
                    break;
                }
                else if(s1[i][n - 1 - j] == '-' && !(u >> j & 1)) {
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            int v = 0;
            for(int j = 0; j < n; ++j) {
                int temp = (u >> j) & 1;
                if(s2[i][n - 1 - j] == '-') {
                    v += (1 << j);
                }
                else if(s2[i][n - 1 - j] == '0') {
                    v += (temp << j);
                }
            }
            if(d[v] > d[u] + val[i]) {
                d[v] = d[u] + val[i];
                q.push((HeapNode){d[v], v});
            }
        }
	}
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        sum = (1 << n) - 1;
        for(int i = 0; i < m; ++i) {
            scanf("%lld%s%s", &val[i], s1[i], s2[i]);
        }
        dijkstra();
        if(d[sum] == INF) puts("0");
        else printf("%lld\n", d[sum]);
    }
    return 0;
}
