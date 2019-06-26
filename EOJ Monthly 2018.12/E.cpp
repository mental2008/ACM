#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=2e5+5;
int n,k;
vector<int> e[maxn];
int sign[maxn];
int dp[maxn];
int m;

bool dfs(int u,int fa) {
    for(auto v:e[u]) {
        if(v==fa) continue;
        if(!dfs(v,u)) return false;
    }
    if(sign[u]) {
        dp[u]=m-1;
        for(auto v:e[u]) {
            if(v==fa||dp[v]>=0) continue;
            dp[u]+=dp[v];
            if(dp[u]<0) return false;
        }
    }
    else {
        dp[u]=-1;
        for(auto v:e[u]) {
            if(v==fa) continue;
            if(dp[v]<0) dp[u]+=dp[v];
        }
        int res=0;
        for(auto v:e[u]) {
            if(v==fa||dp[v]<=0) continue;
            res=max(res,dp[v]);
        }
        if(dp[u]+res>=0) dp[u]+=res;
    }
    return true;
}

bool judge(int limit) {
    m=limit;
    bool ok=dfs(1,0);
    // rep(i,1,n) {
    //     cout<<dp[i]<<"\n";
    // }
    if(ok&&dp[1]>=0) return true;
    return false;
}

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    mem(sign,0);
    rep(i,1,k) {
        int u;
        scanf("%d",&u);
        sign[u]=1;
    }
    // cout<<judge(2)<<"\n";
    // return 0;
    int l=1,r=n;
    int ans;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(judge(mid)) {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}