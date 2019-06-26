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
typedef vector<int> vi;

const ll mod=1e9+7;
const int maxn=1005;
int n;
ll dp[maxn*2][maxn][2];

ll dfs(int i,int j,int pre) {
    if(dp[i][j][pre]!=-1) return dp[i][j][pre];
    if(i==2*n) return 0;
    ll res=0;
    if(j>0) {
        if(2*n-i>j) {
            if(pre==0) {
                res=(dfs(i+1,j+1,1)+1+dfs(i+1,j-1,0))%mod;
                // res=(dfs(i+1,j+1,0)+1+dfs(i+1,j-1,1))%mod;
            }
            else res=(dfs(i+1,j+1,0)+dfs(i+1,j-1,0))%mod;
        }
        else {
            if(pre==0) res=(dfs(i+1,j-1,1)+1)%mod;
            else res=dfs(i+1,j-1,0);
        }
    }
    else {
        if(pre==0) res=(dfs(i+1,j+1,1)+1)%mod;
        else res=dfs(i+1,j+1,0);
    }
    // printf("%d %d %d %lld\n",i,j,pre,res);
    return dp[i][j][pre]=res;
}

int main() {
    scanf("%d",&n);
    mem(dp,-1);
    ll ans=dfs(0,0,0);
    printf("%lld\n",ans);
    return 0;
}