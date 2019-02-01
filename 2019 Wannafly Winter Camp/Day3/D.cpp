#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=14;
ll dp[(1<<maxn)][maxn];
int n,m;
int a[maxn][maxn];
int sz[(1<<maxn)];
int pre[(1<<maxn)];

int main() {
    scanf("%d%d",&n,&m);
    mem(a,0);
    rep(i,1,m) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--; v--;
        a[u][v]=a[v][u]=w;
    }
    rep(S,0,(1<<n)-1) {
        rep(i,0,n-1) {
            if((S>>i)&1) sz[S]++;
            dp[S][i]=-INF;
        }
    }
    rep(i,0,n-1) pre[1<<i]=i;
    rep(S,1,(1<<n)-1) {
        for(int t=S;t;t-=lowbit(t)) {
            int i=pre[lowbit(t)];
            if(sz[S]==1) {
                dp[S][i]=0; continue;
            }
            int P=S^(1<<i);
            for(int T=P;T;T=(T-1)&P) {
                for(int p=T;p;p-=lowbit(p)) {
                    int j=pre[lowbit(p)];
                    if(a[i][j]) dp[S][i]=max(dp[S][i],dp[T][j]+dp[S-T][i]+1ll*a[i][j]*sz[T]*(n-sz[T]));
                }
            }
        }
    }
    ll ans=0;
    rep(i,0,n-1) ans=max(ans,dp[(1<<n)-1][i]);
    printf("%lld\n",ans);
    return 0;
}