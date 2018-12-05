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
const int maxn=3e5+5;
int n;
vector<int> e[maxn];
ll a[maxn];
ll dp[maxn];

void dfs(int u,int fa) {
    dp[u]=a[u];
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
        dp[u]+=max(0ll,dp[v]);
    }
}

ll ans;
int cnt;

void dfs2(int u,int fa) {
    dp[u]=a[u];
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs2(v,u);
        dp[u]+=max(0ll,dp[v]);
    }
    if(dp[u]==ans) {
        dp[u]=-INF;
        cnt++;
    }
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1,0);
    ans=-INF;
    rep(i,1,n) ans=max(ans,dp[i]);
    cnt=0;
    dfs2(1,0);
    printf("%lld %d\n",ans*cnt,cnt);
    return 0;
}