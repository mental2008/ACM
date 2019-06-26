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
int n;
vector<pil> e[maxn];
ll dp[maxn];
ll ans;

void dfs(int u,int fa) {
    dp[u]=a[u];
    int len=e[u].size();
    vector<ll> vec;
    rep(i,0,len-1) {
        int v=e[u][i].fi;
        ll w=e[u][i].se;
        if(v==fa) continue;
        dfs(v,u);
        if(dp[v]-w>=0) {
            // printf("%d %d\n",u,v);
            vec.pb(dp[v]-w);
        }
    }
    sort(vec.begin(),vec.end());
    int p=vec.size();
    // printf("%d\n",p);
    if(p>=2) {
        ans=max(ans,vec[p-1]+vec[p-2]+a[u]);
        // printf("%lld\n",vec[p-1]+vec[p-2]+a[u]);
    }
    if(p>=1) {
        dp[u]+=vec[p-1];
    }
    vec.clear();
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,n-1) {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        e[u].pb(mp(v,w));
        e[v].pb(mp(u,w));
    }
    ans=0;
    dfs(1,0);
    rep(i,1,n) {
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}