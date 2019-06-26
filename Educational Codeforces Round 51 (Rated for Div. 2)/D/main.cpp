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
const ll mod=998244353ll;
const int maxn=1005;
int n,k;
ll dp[maxn][maxn*2][4];

int main() {
    scanf("%d%d",&n,&k);
    mem(dp,0);
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    dp[1][1][3]=1;
    rep(i,2,n) {
        rep(j,1,k) {
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            if(j>=2) dp[i][j][1]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-2][2]+dp[i-1][j-1][3])%mod;
            else dp[i][j][1]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-1][3])%mod;
            if(j>=2) dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j-2][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            else dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            dp[i][j][3]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%mod;
        }
    }
    ll ans=(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod;
    printf("%lld\n",ans);
    return 0;
}
