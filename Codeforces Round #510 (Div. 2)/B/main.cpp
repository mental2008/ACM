#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1005;
ll dp[10];
int n;
char s[10];

int main() {
    rep(i,1,7) dp[i]=INF;
    dp[0]=0;
    scanf("%d",&n);
    rep(i,1,n) {
        ll val;
        scanf("%lld%s",&val,s);
        int u=0;
        int len=strlen(s);
        rep(j,0,len-1) {
            u=u|(1<<(s[j]-'A'));
        }
        dp[u]=min(dp[u],val);
    }
    rep(i,0,7) {
        rep(j,0,7) {
            ll res=dp[i]+dp[j];
            int u=i|j;
            dp[u]=min(dp[u],res);
        }
    }
    if(dp[7]==INF) puts("-1");
    else printf("%lld\n",dp[7]);
    return 0;
}
