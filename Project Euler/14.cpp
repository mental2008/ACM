#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e6+5;
ll dp[3*maxn];
ll dfs(ll x) {
    if(x<maxn&&dp[x]!=-1) return dp[x];
    // printf("%d\n",x);
    ll res;
    if(x%2==0) res=dfs(x/2)+1;
    else res=dfs(3*x+1)+1;
    if(x<maxn) dp[x]=res;
    return res;
}

int main() {
    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    // printf("%d\n",dfs(113383));
    // return 0;
    int ans=1;
    for(int i=1;i<=1000000;++i) {
        if(dfs(ans)<dfs(i)) {
            ans=i;
        }
        // printf("%d\n",i);
    }
    printf("%d\n",ans);
    return 0;
}