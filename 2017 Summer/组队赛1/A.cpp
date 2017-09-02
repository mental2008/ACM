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
const LL INF = 1e14;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1048600;
int n, m;
int sum;
struct Edge {
    int from, to;
    LL cost;
    Edge(int _from, int _to, LL _cost) {
        from = _from, to = _to, cost = _cost;
    }
};
vector<Edge> edges;
vector<int> G[maxn];
LL d[maxn];
bool done[maxn];

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
		for(int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if(d[e.to] > d[u] + e.cost) {
				d[e.to] = d[u] + e.cost;
				q.push((HeapNode){d[e.to], e.to});
			}
		}
	}
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        sum = (1 << n) - 1;
        edges.clear();
        for(int i = 0; i <= sum; ++i) G[i].clear();
        for(int i = 0; i < m; ++i) {
            int B, W;
            LL c;
            scanf("%d%d%lld", &B, &W, &c);
            int temp1 = 0;
            for(int j = 0; j < B; ++j) {
                int val;
                scanf("%d", &val);
                temp1 |= (1 << val);
            }
            int temp2 = 0;
            for(int j = 0; j < W; ++j) {
                int val;
                scanf("%d", &val);
                temp2 |= (1 << val);
            }
            int res = sum - temp1 - temp2;
			for (int sub = res; ; sub = (sub - 1) & res){
				edges.push_back(Edge(sub | temp1, sub | temp2, c));
                int k = (int)edges.size();
                G[sub | temp1].push_back(k - 1);
				if(sub == 0)	break;
			}
        }
        dijkstra();
        if(d[sum] == INF) puts("Too naive!");
        else printf("%lld\n", d[sum]);
    }
    return 0;
}
