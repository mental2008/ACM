#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
struct Edge {
	int from, to;
	double rate, commission;
	Edge(int _from, int _to, double _rate, double _commission) {
		from = _from, to = _to;
		rate = _rate, commission = _commission;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int cnt[maxn];
double d[maxn];
int inq[maxn];
int n, m;
int S;
double V;

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(inq, 0, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
}

void AddEdge(int from, int to, double rate, double commission) {
	edges.push_back(Edge(from, to, rate, commission));
	int k = edges.size();
	G[from].push_back(k - 1);
}

bool bellman_ford() {
	for(int i = 1; i <= n; i++) d[i] = 0;
	d[S] = V;
	queue<int> q;
	inq[S] = true;
	q.push(S);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if(d[e.to] < (d[u] - e.commission) * e.rate) {
				d[e.to] = (d[u] - e.commission) * e.rate;
				if(!inq[e.to]) {
					q.push(e.to);
					inq[e.to] = true;
					if(++cnt[e.to] > n) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		scanf("%d %lf", &S, &V);
		for(int i = 1; i <= m; i++) {
			int a, b;
			double rab, cab, rba, cba;
			scanf("%d%d%lf%lf%lf%lf", &a, &b, &rab, &cab, &rba, &cba);
			AddEdge(a, b, rab, cab);
			AddEdge(b, a, rba, cba);
		}
		if(bellman_ford()) puts("NO");
		else puts("YES");
	}
	return 0;
}
