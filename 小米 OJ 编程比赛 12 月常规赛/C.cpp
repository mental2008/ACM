#include<bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=605;
struct Edge {
    int from,to,cap,flow,cost;
};
int n,m;
vector<Edge> edges;
vector<int> G[maxn];
int inq[maxn];
int d[maxn];
int p[maxn];
int a[maxn];
void init() {
    for(int i=0;i<maxn;++i) G[i].clear();
    edges.clear();
}
void AddEdge(int from,int to,int cap,int cost) {
    edges.push_back((Edge){from,to,cap,0,cost});
    edges.push_back((Edge){to,from,0,0,-cost});
    m=edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}
bool BellmanFord(int s,int t,int &flow,int &cost) {
    for(int i=0;i<maxn;++i) d[i]=INF;
    memset(inq,0,sizeof(inq));
    d[s]=0;
    p[s]=0;
    inq[s]=1;
    a[s]=INF;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int u=Q.front(); Q.pop();
        inq[u]=0;
        for(int i=0;i<G[u].size();++i) {
            Edge& e=edges[G[u][i]];
            if(e.cap>e.flow&&d[e.to]>d[u]+e.cost) {
                d[e.to]=d[u]+e.cost;
                p[e.to]=G[u][i];
                a[e.to]=min(a[u],e.cap-e.flow);
                if(!inq[e.to]) {
                    Q.push(e.to);
                    inq[e.to]=1;
                }
            }
        }
    }
    if(d[t]==INF) return false;
    flow+=a[t];
    cost+=d[t]*a[t];
    int u=t;
    while(u!=s) {
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }
    return true;
}
int Mincost(int s,int t) {
    int flow=0, cost=0;
    // cout<<s<<" "<<t<<"\n";
    while(BellmanFord(s,t,flow,cost));
    return cost;
}
struct Point {
    double x,y;
    Point() {}
    Point(double a,double b) {
        x=a;
        y=b;
    }
};
bool judge(Point a,Point b,Point c,Point d)
{
    if(!(min(a.x,b.x)<=max(c.x,d.x) && min(c.y,d.y)<=max(a.y,b.y)&&min(c.x,d.x)<=max(a.x,b.x) && min(a.y,b.y)<=max(c.y,d.y)))
        return false;
    double u,v,w,z;
    u=(c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
       v=(d.x-a.x)*(b.y-a.y)-(b.x-a.x)*(d.y-a.y);
       w=(a.x-c.x)*(d.y-c.y)-(d.x-c.x)*(a.y-c.y);
       z=(b.x-c.x)*(d.y-c.y)-(d.x-c.x)*(b.y-c.y);
       return (u*v<=0.00000001 && w*z<=0.00000001);
}
int xp[maxn],xq[maxn];
int yp[maxn],yq[maxn];
int v[maxn];

int main() {
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;++i) {
            scanf("%d%d%d%d%d",&xp[i],&yp[i],&xq[i],&yq[i],&v[i]);
        }
        init();
        for(int i=1;i<=n;++i) {
            AddEdge(0,i,1,-v[i]);
            AddEdge(i,2*n+1,1,0);
            AddEdge(n+i,2*n+1,1,0);
            for(int j=1;j<=n;++j) {
                if(i==j) continue;
                if(v[i]>v[j]&&judge({xp[i],yp[i]},{xq[i],yq[i]},{xp[j],yp[j]},{xq[j],yq[j]})) {
                    AddEdge(i,n+j,1,-((i+j)/2*(v[i]+v[j])));
                    // cout<<i<<" "<<j<<" "<<((i+j)/2*(v[i]+v[j])+v[i])<<"\n";
                }
            }
        }
        // for(int i=0;i<m;++i) printf("%d %d %d\n",edges[i].from,edges[i].to,edges[i].cost);
        printf("%d\n",-Mincost(0,2*n+1));
    }
    return 0;
}