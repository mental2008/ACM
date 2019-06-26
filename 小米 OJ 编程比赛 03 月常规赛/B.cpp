#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int maxn = 350;
int n,m;
char s[maxn][maxn];
int pp[4]={0,0,1,-1};
int qq[4]={1,-1,0,0};

struct Edge { int from, to, cap, flow, cost; };
vector<Edge> edges;
vector<int> G[maxn];
int inque[maxn];   //spfa
int d[maxn];    //源点到当前点的最短路
int p[maxn];    //入弧编号
int a[maxn];    //可改进量

void init(int n)
{
    for(int i=0; i<=n; i++) G[i].clear();
    edges.clear();
}

void add_edge(int from, int to, int cap, int cost)
{
    edges.push_back((Edge){from, to, cap, 0, cost});
    edges.push_back((Edge){to, from, 0, 0, -cost});
    int m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}
bool spfa(int s, int t, int &flow, long long &cost)
{
    memset(d, 0x3f, sizeof(d));
    memset(inque, 0, sizeof(inque));
    d[s] = 0; inque[s] = 1;
    a[s] = inf; p[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int u = que.front(); que.pop();
        inque[u] = 0;
        for(int i=0; i<G[u].size(); i++){
            Edge e = edges[G[u][i]];
            if(e.cap>e.flow && d[e.to]>d[u]+e.cost){
                d[e.to] = d[u] + e.cost;
                if(!inque[e.to]) que.push(e.to), inque[e.to]=1;
                p[e.to] = G[u][i];
                a[e.to] = min(a[u], e.cap-e.flow);
            }
        }
    }
    if(d[t] == inf) return false;
    flow += a[t];
    cost += (long long)a[t]*(long long)d[t];
    for(int u=t; u!=s; u=edges[p[u]].from){
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
    }
    return true;
}
int MCMF(int s, int t, long long &cost)
{
    int flow = 0; cost = 0;
    while(spfa(s, t, flow, cost));
    return flow;
}
int x[maxn],y[maxn];
int dis[maxn][maxn];
struct Node {
    int x,y;
    int step;
    Node() {}
    Node(int x,int y,int step):x(x),y(y),step(step) {}
};
bool vis[maxn][maxn];
queue<Node> Q;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d%d",&n,&m);
        rep(i,0,n-1) scanf("%s",s[i]);
        init(maxn-1);
        int sum=0;
        int res=0;
        rep(i,0,n-1) {
            rep(j,0,m-1) {
                if((s[i][j]>='1'&&s[i][j]<='9')||s[i][j]=='S') {
                    ++sum;
                    if(s[i][j]>='1'&&s[i][j]<='9') res+=s[i][j]-'1';
                    printf("%d %d %d\n",sum,i,j);
                    x[sum]=i;
                    y[sum]=j;
                }
            }
        }
        // printf("sum=%d\n",sum);
        rep(i,1,sum) {
            mem(dis,0x3f);
            mem(vis,0);
            dis[x[i]][y[i]]=0;
            vis[x[i]][y[i]]=1;
            Q.push(Node(x[i],y[i],0));
            while(!Q.empty()) {
                Node node=Q.front();
                Q.pop();
                dis[node.x][node.y]=min(dis[node.x][node.y],node.step);
                rep(i,0,3) {
                    int xx=node.x+pp[i];
                    int yy=node.y+qq[i];
                    if(xx<0||xx>=n||yy<0||yy>=m) continue;
                    if(vis[xx][yy]||s[xx][yy]=='#') continue;
                    vis[xx][yy]=1;
                    Q.push(Node(xx,yy,node.step+1));
                }
            }
            if(s[x[i]][y[i]]=='S') {
                add_edge(0,i,1,0);
                add_edge(i,i+sum,1,0);
                printf("%d -> %d, cap = %d, cost = %d\n",0,i,1,0);
                printf("%d -> %d, cap = %d, cost = %d\n",i,i+sum,1,0);
            }
            else {
                add_edge(0,i,s[x[i]][y[i]]-'1',0);
                add_edge(i,i+sum,s[x[i]][y[i]]-'0',0);
                add_edge(i+sum,2*sum+1,inf,0);
                printf("%d -> %d, cap = %d, cost = %d\n",0,i,s[x[i]][y[i]]-'1',0);
                printf("%d -> %d, cap = %d, cost = %d\n",i,i+sum,s[x[i]][y[i]]-'0',0);
                printf("%d -> %d, cap = %d, cost = %d\n",i+sum,2*sum+1,inf,0);
            }
            rep(j,1,sum) {
                if(i==j) continue;
                if(dis[x[j]][y[j]]>=1061109567) continue;
                add_edge(i+sum,j,inf,dis[x[j]][y[j]]);
                printf("%d -> %d, cap = %d, cost = %d\n",i+sum,j,inf,dis[x[j]][y[j]]);
            }
        }
        ll cost;
        int ans=MCMF(0,2*sum+1,cost);
        printf("%d\n",ans);
        if(ans==res+1) printf("%lld\n",cost);
        else puts("-1");
    }
    return 0;
}