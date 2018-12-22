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
typedef double db;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=5e5+5;
ll a[maxn];
int fa[maxn][20];
vector<int> e[maxn];
int n;
ll ans;

void dfs(int u,int pre) {
    fa[u][0]=pre;
    rep(i,1,19) {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    ll res=INF;
    rep(i,0,19) {
        res=min(res,(1ll+i)*a[fa[u][i]]+a[u]);
    }
    if(u!=pre) ans+=res;
    for(auto v:e[u]) {
        if(v==pre) continue;
        dfs(v,u);
    }
}

int main() {
    scanf("%d",&n);
    int rt=0;
    rep(i,1,n) {
        scanf("%lld",&a[i]);
        if(i==1||a[i]<a[rt]) rt=i;
    }
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    ans=0;
    dfs(rt,rt);
    printf("%lld\n",ans);
    return 0;
}