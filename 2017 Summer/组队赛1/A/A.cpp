#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int64;
typedef pair<int64,int> pli;
const int MAX_n = 20, MAX_m = 1000;
const int MAX_V = 1<<MAX_n, MAX_E = MAX_m*(1<<MAX_n/2);
const int64 INF = 0x3f3f3f3f3f3f3f3fLL;
int nxt[MAX_V+MAX_E], to[MAX_V+MAX_E], cost[MAX_V+MAX_E], esz;
void init_es(int V){
	for (int i = 0; i < V; ++i)
		nxt[i] = i;
	esz = V;
}
void add_edge(int u,int v,int c){
	nxt[esz] = nxt[u], to[esz] = v, cost[esz] = c;
	nxt[u] = esz++;
}
int64 dist[MAX_V];
priority_queue<pli>	que;
int64 dijkstra(int s,int t,int V){
	memset(dist,0x3f,sizeof(int64)*V);
	while(!que.empty())	que.pop();
	que.push(make_pair(s,0));	dist[s] = 0;
	while(!que.empty()){
		pli p = que.top();	que.pop();
		int v = p.second, d = -p.first;
		if(dist[v] < d)	continue;
		if(v == t)	break;
		for (int e = nxt[v]; e != v; e = nxt[e]){
			const int &w = to[e];
			const int &c = cost[e];
			if(dist[w] > d+c){
				dist[w] = d+c;
				que.push(make_pair(-d-c,w));
			}
		}
	}
	return dist[t];
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		init_es(1<<n);
		for (int i = 0; i < m; ++i){
			int B,W,c;
			scanf("%d%d%d",&B,&W,&c);
			int u = 0, v = 0;
			for (int j = 0; j < B; ++j){
				int t;
				scanf("%d",&t);
				u |= 1<<t;
			}
			for (int j = 0; j < W; ++j){
				int t;
				scanf("%d",&t);
				v |= 1<<t;
			}
			int res = (1<<n)-1-u-v;
			for (int sub = res; ; sub = (sub-1)&res){
				add_edge(sub|u,sub|v,c);
				if(sub == 0)	break;
			}
		}
		int64 ans = dijkstra(0,(1<<n)-1,1<<n);
		if(ans == INF)	puts("Too naive!");
		else			printf("%lld\n",ans);
	}
}

