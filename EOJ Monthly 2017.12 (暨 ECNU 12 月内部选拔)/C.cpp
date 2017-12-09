#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
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

int main() {
    ios::sync_with_stdio(false);
    string s;
    int count[30];
    while(cin >> s) {
        mem(count, 0);
        int len = s.size();
        for(int i = 0; i < len; ++i) {
            int num = s[i] - 'a';
            count[num]++;
        }
        init();
        for(int i = 0; i < 26; ++i) {
            AddEdge(0, i + 1, count[i]);
            AddEdge(26 + i + 1, 54, count[i]);
            for(int j = 0; j < 26; ++j) {
                if(i == j) continue;
                AddEdge(i + 1, 26 + j + 1, INF);
            }
        }
        int ans = Maxflow(0, 54);
        if(ans == len) {
            string output = s;
            for(int i = 0; i < len; ++i) {
                int num = s[i] - 'a';
                int k = G[num + 1].size();
                for(int j = 0; j < k; ++j) {
                    Edge &e = edges[G[num + 1][j]];
                    if(e.cap == 0) continue;
                    if(e.flow > 0) {
                        e.flow--;
                        output[i] = 'a' + e.to - 1 - 26;
                        break;
                    }
                }
            }
            cout << output << '\n';
        }
        else cout << "impossible\n";
    }
    return 0;
}
