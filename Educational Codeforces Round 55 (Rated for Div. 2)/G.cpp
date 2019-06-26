#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,ll> pil;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int V=2e3+5;
int n,m;
struct Edge{
	int to,rev;
	ll cap;
	Edge(){}
	Edge(int to,ll cap,int rev):to(to),rev(rev),cap(cap){}
};
vector<Edge> G[V];
int iter[V],level[V];
void addEdge(int u,int v,ll w){
	G[u].push_back(Edge(v,w,(int)G[v].size()));
	G[v].push_back(Edge(u,0,(int)G[u].size()-1));
}
queue<int>que;
void bfs(int s){
	mem(level,-1);
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<(int)G[v].size();i++){
			Edge& e=G[v][i];
			if(level[e.to]<0 && e.cap>0) level[e.to]=level[v]+1,que.push(e.to);
		}
	}
}
ll dfs(int s,int t,ll f){
	if(s==t) return f;
	for(int& i=iter[s];i<(int)G[s].size();i++){
		Edge& e=G[s][i];
		if(level[s]<level[e.to] && e.cap>0){
			ll d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d,G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

ll max_flow(int s,int t){
	ll flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		mem(iter,0);
		while(1){
			ll f=dfs(s,t,INF);	
			if(!f) break;
			flow+=f;
		}
	}
}

int main() {
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    rep(i,1,n) {
        ll val;
        scanf("%lld",&val);
        addEdge(i,t,val);
    }
    ll sum=0;
    rep(i,1,m) {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        addEdge(s,i+n,w);
        addEdge(i+n,u,INF);
        addEdge(i+n,v,INF);
        sum+=w;
    }
    sum-=max_flow(s,t);
    printf("%lld\n",sum);
    return 0;
}