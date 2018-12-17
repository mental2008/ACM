#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll mod=998244353ll;
const int maxn=2005;
int n,m,k;
ll dp[maxn][maxn];

int main() {
    scanf("%d%d%d",&n,&m,&k);
    dp[1][0]=m;
    rep(i,2,n) {
        dp[i][0]=dp[i-1][0];
        rep(j,1,i-1) {
            dp[i][j]=(dp[i-1][j-1]*(m-1)%mod+dp[i-1][j])%mod;
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}