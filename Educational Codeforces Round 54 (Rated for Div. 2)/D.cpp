#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=3e5+5;

int n,m,k;
vector<int> e[maxn];
vector<ll> dis[maxn];
map<int,int> sign[maxn];
struct Node {
    int u;
    ll d;
    bool operator<(const Node& e) const {
        return d>e.d;
    }
};
priority_queue<Node> Q;
bool vis[maxn];
int pre[maxn];
ll d[maxn];
vector<int> mst[maxn];
int ans[maxn];
int cnt;

void dfs(int u,int fa) {
    for(auto v:mst[u]) {
        if(v==fa) continue;
        ans[++cnt]=sign[u][v];
        dfs(v,u);
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,m) {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        e[u].pb(v);
        e[v].pb(u);
        dis[u].pb(w);
        dis[v].pb(w);
        sign[u][v]=sign[v][u]=i;
    }
    Q.push({1,0});
    mem(vis,0);
    mem(d,0x3f);
    d[1]=0;
    while(!Q.empty()) {
        Node x=Q.top();
        Q.pop();
        int u=x.u;
        if(vis[u]) continue;
        vis[u]=1;
        int len=e[u].size();
        rep(i,0,len-1) {
            int v=e[u][i];
            ll w=dis[u][i];
            if(d[u]+w<d[v]) {
                pre[v]=u;
                d[v]=d[u]+w;
                Q.push({v,d[v]});
            }
        }
    }
    rep(i,2,n) {
        mst[pre[i]].pb(i);
    }
    cnt=0;
    dfs(1,0);
    k=min(k,n-1);
    printf("%d\n",k);
    rep(i,1,k) {
        printf("%d%c",ans[i],(i==k?'\n':' '));
    }
    return 0;
}