#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,ll> pil;
const int maxn=3e5+5;
ll a[maxn];
set<pil> e[maxn];
int n;
struct Node {
    int u,deg;
    bool operator<(const Node& e) const {
        return deg>e.deg;
    }
};
int degree[maxn];
bool vis[maxn];
priority_queue<Node> q;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    mem(degree,0);
    rep(i,1,n-1) {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        e[u].insert(mp(v,w));
        e[v].insert(mp(u,w));
        degree[u]++;
        degree[v]++;
    }
    rep(i,1,n) q.push({i,degree[i]});
    mem(vis,0);
    while(!q.empty()) {
        Node node=q.top();
        q.pop();
        if(vis[node.u]) continue;
        vis[node.u]=1;
        auto pos=e[node.u].begin();
        int v=(*pos).fi;
        ll w=(*pos).se;
        if(a[node.u]-w>=0) {
            a[v]+=(a[node.u]-w);
        }
        e[node.u].erase(mp(v,w));
        degree[node.u]--;
        e[v].erase(mp(node.u,w));
        degree[v]--;
        q.push({v,degree[v]});
    }
    ll ans=0;
    rep(i,1,n) {
        ans=max(ans,a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}