#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e3+5;
ll a[maxn],b[maxn],c[maxn];
ll dp[maxn][maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        int n;
        ll res;
        scanf("%d%lld",&n,&res);
        rep(i,1,n) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        rep(i,1,n) {
            rep(j,0,n) dp[i][j]=INF;
        }
        if(a[n]+1<=b[n]) dp[n][1]=a[n]+1;
        dp[n][0]=1;
        per(i,n-1,1) {
            rep(j,0,n) {
                if(dp[i+1][j]!=INF) {
                    ll x=max(dp[i+1][j]-c[i],1ll);
                    dp[i][j]=min(dp[i][j],x);
                }
                if(j>0&&dp[i+1][j-1]!=INF) {
                    ll x=max(dp[i+1][j-1]+a[i]-c[i],a[i]+1ll);
                    if(x<=b[i]) dp[i][j]=min(dp[i][j],x);
                }
            }
        }
        int ans;
        per(i,n,0) {
            if(dp[1][i]<=res) {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}