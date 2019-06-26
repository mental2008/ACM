#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n,m,k;
ll h[maxn];
map<int,ll> e[maxn];
struct Node {
    int x;
    ll d;
    Node() {}
    Node(int _x,ll _d) {
        x=_x;
        d=_d;
    }
    bool operator<(const Node& e) const {
        return d>e.d;
    }
};
bool vis[maxn];
ll dis[maxn];
priority_queue<Node> Q;

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n) {
        scanf("%lld",&h[i]);
    }
    rep(i,1,m) {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        ll temp=e[u][v];
        if(temp==0||temp>w) {
            e[u][v]=e[v][u]=w;
        }
    }
    ll ans=0;
    Node start(1,0);
    mem(vis,0);
    mem(dis,0x3f);
    dis[1]=0;
    Q.push(start);
    while(!Q.empty()) {
        Node node=Q.top();
        Q.pop();
        if(vis[node.x]) continue;
        vis[node.x]=1;
        for(auto it:e[node.x]) {
            int v=it.fi;
            ll w=it.se;
            ll temp=0;
            if(h[v]>h[1]+k) temp+=1ll*(h[v]-h[1]-k)*(h[v]-h[1]-k);
            if(dis[v]>dis[node.x]+w+temp) {
                dis[v]=dis[node.x]+w+temp;
                Node newnode(v,dis[v]);
                Q.push(newnode);
            }
        }
    }
    printf("%lld\n",dis[n]);
    return 0;
}