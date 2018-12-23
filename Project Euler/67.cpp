#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=105;
ll a[maxn][maxn];
ll dp[maxn][maxn];
int n=100;

int main() {
    freopen("67.in","r",stdin);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=i;++j) {
            scanf("%lld",&a[i][j]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=i;++j) {
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
            ans=max(dp[i][j],ans);
        }
    }
    printf("%lld\n",ans);
    return 0;
}