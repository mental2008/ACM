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
typedef double db;
const db exps=1e-10;
const int maxn=1e5+5;
int n;
ll s;
vector<int> e[maxn];
db dp[maxn];
db m;
db lef;

void dfs(int u,int fa) {
    int len=e[u].size();
    dp[u]=0;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
    if(len==1) {
        if(u==1) {
            for(auto v:e[u]) {
                lef-=m-dp[v];
            }
        }
        return;
    }
    for(auto v:e[u]) {
        if(v==fa) continue;
        if(len==2) {
            if(u==1) {
                lef-=m/2.0-dp[v];
                dp[u]=max(dp[u],m/2.0);
            }
            else {
                dp[u]=dp[v];
            }
        }
        else {
            lef-=m/2.0-dp[v];
            dp[u]=max(dp[u],m/2.0);
        }
    }
    return;
}
int deg[maxn];

int main() {
    scanf("%d%lld",&n,&s);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    int sum=0,p=0;
    rep(i,1,n) {
        if(deg[i]==2) sum++;
        else if(deg[i]==1) p++;
    }
    if(sum==n-2&&p==2) {
        return 0*printf("%lld\n",s);
    }

    // m=2.5;
    // lef=s;
    // dfs(1,0);
    // rep(i,1,n) {
    //     printf("%d %.10lf\n",i,dp[i]);
    // }
    // printf("%.10lf\n",lef);
    // return 0;

    db l=0,r=s;
    db ans;
    int cnt=0;
    while(1) {
        cnt++;
        if(cnt==50) break;
        db mid=(l+r)/2.0;
        m=mid;
        lef=s;
        dfs(1,0);
        if(lef<=0) {
            ans=mid;
            r=mid;
        }
        else {
            l=mid;
        }
    }
    printf("%.10lf\n",ans);
    return 0;
}