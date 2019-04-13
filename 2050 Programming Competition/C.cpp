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
ll dp[maxn*2];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll n,m,k;
        ll a,b,c;
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&a,&b,&c);
        ll ans=INF;
        dp[0]=0;
        rep(i,1,2000) {
            dp[i]=min(dp[max(i-2,0)]+a,dp[max(i-3,0)]+b);
        }
        rep(i,0,k) {
            ll x=k-i+n;
            ll y=k-i+m;
            ll res=c*i+dp[x]+dp[y];
            ans=min(ans,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}