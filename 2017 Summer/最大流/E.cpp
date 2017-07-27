#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 30005;
const int INF = 0x3f3f3f3f;
int n, m;
int s, t;
struct Edge {
	int from, to, cap, flow;
	Edge(int _from, int _to, int _cap, int _flow) {
		from = _from, to = _to, cap = _cap, flow = _flow;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int p[maxn];
int d[maxn];
int num[maxn];
bool vis[maxn];
int cur[maxn];
struct Segment {
	int down, right;
	bool sign;
	int downNum, rightNum;
	int valueNum;
} segment[105][105];
/*
sign
true black
false white
*/
char str[10];
int ans[maxn];

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
	for(int i = 0; i < maxn; i++) d[i] = INF;
	queue<int> Q;
	vis[t] = 1;
	d[t] = 0;
	Q.push(t);
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(int i = 0; i < G[x].size(); i++) {
			Edge e = edges[G[x][i] ^ 1];
			if(!vis[e.from] && e.cap > e.flow) {
				vis[e.from] = 1;
				d[e.from] = d[x] + 1;
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
	memset(num, 0, sizeof(num));
	memset(cur, 0, sizeof(cur));
	BFS();
	for(int i = 0; i <= t; i++) if(d[i] < INF) num[d[i]]++;
	int flow = 0, x = s;
	while(d[x] <= t) {
		if(x == t) {
			flow += Augment();
			x = s;
		}
		bool ok = false;
		for(int i = cur[x]; i < G[x].size(); i++) {
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
			int k = t;
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

int strToValue(char *ch) {
	int len = strlen(ch);
	int sum = 0;
	for(int i = 0; i < len; i++) {
		sum = sum * 10 + (ch[i] - '0');
	}
	return sum;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%s", str);
				if(!strcmp(str, "XXXXXXX")) {
					segment[i][j].sign = true;
					segment[i][j].down = 0;
					segment[i][j].right = 0;
				}
				else if(!strcmp(str, ".......")) {
					segment[i][j].sign = false;
				}
				else {
					segment[i][j].sign = true;
					char strdown[10], strright[10];
					strncpy(strdown, str, 3);
					if(strcmp(strdown, "XXX")) segment[i][j].down = strToValue(strdown);
					else segment[i][j].down = 0;
					strncpy(strright, str + 4, 3);
					if(strcmp(strright, "XXX")) segment[i][j].right = strToValue(strright);
					else segment[i][j].right = 0;
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(segment[i][j].sign) {
					if(segment[i][j].down) {
						segment[i][j].downNum = ++cnt;
					}
					if(segment[i][j].right) {
						segment[i][j].rightNum = ++cnt;
					}
				}
				else {
					segment[i][j].valueNum = ++cnt;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(segment[i][j].sign) {
					if(segment[i][j].down) {
						for(int x = i + 1; x <= n; x++) {
							if(!segment[x][j].sign) {
								AddEdge(segment[x][j].valueNum, segment[i][j].downNum, 8);
								segment[i][j].down--;
							}
							else break;
						}
						AddEdge(segment[i][j].downNum, cnt + 1, segment[i][j].down);
					}
					if(segment[i][j].right) {
						for(int y = j + 1; y <= m; y++) {
							if(!segment[i][y].sign) {
								AddEdge(segment[i][j].rightNum, segment[i][y].valueNum, 8);
								segment[i][j].right--;
							}
							else break;
						}
						AddEdge(0, segment[i][j].rightNum, segment[i][j].right);
					}
				}
			}
		}
		int res = Maxflow(0, cnt + 1);
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(!segment[i][j].sign) {
					for(int k = 0; k < G[segment[i][j].valueNum].size(); k++) {
						Edge e = edges[G[segment[i][j].valueNum][k]];
						if(e.cap > 0) {
							ans[segment[i][j].valueNum] = e.flow + 1;
							break;
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(segment[i][j].sign) printf("_");
				else printf("%d", ans[segment[i][j].valueNum]);
				if(j != m) printf(" "); 
			}
			puts("");
		}
	}
	return 0;
}
