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
typedef pair<int,int> pii;

const ll mod=1e9+7;
const int maxn=1005;
int n,m;
vector<int> e[maxn];
vector<int> p[maxn];
vector<pii> s[maxn];
ll dis[maxn][maxn];
ll dp[maxn];
ll dep[maxn];
ll ans;

void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}

void dfs2(int u,int fa,ll res,int pre) {
    int len=p[u].size();
    // printf("%d %d %lld %lld %lld\n",u,pre,dp[pre],res,(res+dp[pre])*n%mod);
    ans=(ans+(res+dp[pre])*n%mod)%mod;
    rep(i,0,len-1) {
        int v=p[u][i];
        if(v==fa) continue;
        // ans=(ans+dp[s[u][i].fi]*n%mod)%mod;
        ll temp=0;
        if(fa==0) temp=dp[s[u][i].fi];
        dfs2(v,u,(res+n+temp+dis[pre][s[u][i].fi]*n%mod)%mod,s[u][i].se);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    rep(i,1,n) {
        dep[0]=-1;
        dfs(i,0);
        dp[i]=0;
        rep(j,1,n) {
            dis[i][j]=dep[j];
            dp[i]=(dp[i]+dep[j])%mod;
        }
    }
    rep(i,1,m-1) {
        int a,b,u,v;
        scanf("%d%d%d%d",&a,&b,&u,&v);
        p[a].pb(b);
        p[b].pb(a);
        s[a].pb(mp(u,v));
        s[b].pb(mp(v,u));
    }
    ll cc=0;
    rep(i,1,n) {
        rep(j,1,n) {
            cc=(cc+dis[i][j])%mod;
            // printf("%d %d %lld\n",i,j,dis[i][j]);
        }
    }
    // printf("%lld\n",cc);
    ans=0;
    rep(i,1,m) {
        // int len=p[i].size();
        // rep(j,0,len-1) {
        //     int v=p[i][j];
        //     ans=(ans+dp[s[i][j].fi])%mod;
        //     // printf("%d %d %lld\n",i,s[i][j],dp[s[i][j]]);
        // }
        ans=(ans+cc)%mod;
        dfs2(i,0,0,0);
        // printf("%lld\n",ans);
        // break;
    }
    ll temp=(mod+1)/2;
    ans=(ans*temp)%mod;
    printf("%lld\n",ans);
    return 0;
}

// 56 ac
// 74 ac