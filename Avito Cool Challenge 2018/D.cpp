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
typedef pair<int,int> pii;
const int maxn=1e5+5;
int n,m,k;
struct Edge {
    int u,v,w;
    bool operator<(const Edge& e) const {
        return w<e.w;
    }
} edge[maxn];
int fa[maxn];
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool connect(int x,int y) {
    int fa_x=find(x);
    int fa_y=find(y);
    if(fa_x==fa_y) return false;
    else {
        fa[fa_x]=fa_y;
        return true;
    }
}
vector<int> vec;
int sign[maxn];
vector<pii> e[maxn];
int ans;

void dfs(int u,int fa,int w) {
    if(sign[u]) {
        ans=max(ans,w);
        // printf("%d\n",w);
    }
    for(auto p:e[u]) {
        if(p.fi==fa) continue;
        dfs(p.fi,u,max(w,p.se));
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,k) {
        int val;
        scanf("%d",&val);
        vec.pb(val);
        sign[val]=1;
    }
    rep(i,1,m) {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    rep(i,1,n) fa[i]=i;
    sort(edge+1,edge+1+m);
    ans=0;
    rep(i,1,m) {
        if(connect(edge[i].u,edge[i].v)) {
            e[edge[i].u].pb(mp(edge[i].v,edge[i].w));
            e[edge[i].v].pb(mp(edge[i].u,edge[i].w));
        }
    }
    dfs(vec[0],0,0);
    rep(i,1,k) printf("%d%c",ans,(i==k?'\n':' '));
    return 0;
}