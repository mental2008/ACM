#include<bits/stdc++.h>
 
using namespace std;
 
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1005;
 
int n,k;
int a[maxn];
vector<int> e[maxn];
int f[maxn][maxn];
int g[maxn];
ll t;
 
void dfs(int u,int fa) {
    rep(i,1,n) {
        if(a[i]<=a[u]&&a[u]<=(ll)a[i]+t) f[u][i]=0;
        else f[u][i]=inf;
    }
    g[u]=inf;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
        rep(i,1,n) {
            f[u][i]+=min(f[v][i],g[v]+1);
        }
    }
    rep(i,1,n) g[u]=min(g[u],f[u][i]);
}
 
int chk(ll limit) {
    t=limit;
    dfs(1,0);
    return g[1];
}
 
int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    ll l=0,r=2e9;
    ll ans;
    while(l<=r) {
        ll mid=(l+r)>>1;
        if(chk(mid)<=k) {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}