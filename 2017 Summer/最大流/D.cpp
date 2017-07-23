//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 2005;
const int INF = (1 << 30) - 1;
int row, col;
int s, t;
int dis;
char pillar[30][30], lizard[30][30];
struct Edge {
	int from, to, cap, flow;
	Edge(int _from, int _to, int _cap, int _flow) {
		from = _from, to = _to, cap = _cap, flow = _flow;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int p[maxn];
int num[maxn];
int d[maxn];
int cur[maxn];
bool vis[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
}

void AddEdge(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

void BFS() {
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	Q.push(t);
	vis[t] = 1;
	memset(d, -1, sizeof(d));
	d[t] = 0;
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(int i = 0; i < G[x].size(); i++) {
			Edge e = edges[G[x][i] ^ 1];
			if(!vis[e.from] && e.cap > e.flow) {
				d[e.from] = d[x] + 1;
				vis[e.from] = 1;
				Q.push(e.from);
			}
		}
	}
}

int Augment() {
	int x = t, a = INF;
	while(x != s) {
		Edge e = edges[p[x]];
		a = min(a, e.cap - e.flow);
		x = e.from;
	}
	x = t;
	while(x != s) {
		edges[p[x]].flow += a;
		edges[p[x] ^ 1].flow -= a;
		x = edges[p[x]].from;
	}
	return a;
}

int Maxflow(int u, int v) {
	s = u, t = v;
	int flow = 0, x = s;
	BFS();
	memset(num, 0, sizeof(num));
	for(int i = 0; i <= row * col * 2 + 1; i++) if(d[i] != -1) num[d[i]]++;
	memset(cur, 0, sizeof(cur));
	while(d[x] <= t) {
		if(x == t) {
			flow += Augment();
			x = s;
		}
		bool ok = false;
		for(int i = 0; i < G[x].size(); i++) {
			Edge e = edges[G[x][i]];
			if(e.cap > e.flow && d[x] == d[e.to] + 1) {
				ok = true;
				p[e.to] = G[x][i];
				cur[x] = i;
				x = e.to;
				break;
			}
		}
		if(!ok) {
			int k = row * col * 2;
			for(int i = 0; i < G[x].size(); i++) {
				Edge e = edges[G[x][i]];
				if(e.cap > e.flow) k = min(k, d[e.to]);
			}
			if(--num[d[x]] == 0) break;
			num[d[x] = k + 1]++;
			cur[x] = 0;
			if(x != s) x = edges[p[x]].from;
		}
	}
	return flow;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	for(int times = 1; times <= caseCnt; times++) {
		scanf("%d%d", &row, &dis);
		for(int i = 0; i < row; i++) {
			scanf("%s", pillar[i]);
		}
		for(int i = 0; i < row; i++) {
			scanf("%s", lizard[i]);
		}
		col = (int)strlen(pillar[0]);
		init();
		int sum = 0;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				int id = i * col + j + 1;  
				if(lizard[i][j] == 'L') {
					AddEdge(0, id, 1);
					sum++;
				}
				if(pillar[i][j] != '0') {
					AddEdge(id, id + row * col, pillar[i][j] - '0');
					if(i - dis < 0 || i + dis >= row || j - dis < 0 || j + dis >= col) {
						AddEdge(id + row * col, row * col * 2 + 1, INF);
					}
					else {
						for(int x = 0; x < row; x++) {
							for(int y = 0; y < col; y++) {
								if(x == i && y == j) continue;
								if(pillar[x][y] != '0') {
									if(abs(x - i) + abs(y - j) <= dis) {
										int idxy = x * col + y + 1;
										AddEdge(id + row * col, idxy, INF);
									}
								}
							}
						}
					}
				}
			}
		}
		int result = Maxflow(0, row * col * 2 + 1);
		if(result == sum) printf("Case #%d: no lizard was left behind.\n", times);
		else if(result + 1 == sum) printf("Case #%d: 1 lizard was left behind.\n", times);
		else printf("Case #%d: %d lizards were left behind.\n", times, sum - result);
	}
	return 0;
}
