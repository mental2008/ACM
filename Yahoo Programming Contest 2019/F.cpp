#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const ll mod=998244353ll;
const int maxn=2050;
char s[maxn];
int n;
ll dp[maxn*2][maxn*2];
ll pre[maxn];

int main() {
    while(~scanf("%s",s+1)) {
        n=strlen(s+1);
        mem(dp,0);
        dp[0][0]=1;
        pre[0]=0;
        rep(i,1,n) {
            ll temp=0;
            if(s[i]=='0') temp=2;
            else if(s[i]=='1') temp=1;
            pre[i]=pre[i-1]+temp;
        }
        rep(i,1,2*n) {
            rep(j,0,2*n) {
                if(i<=n) {
                    if((2*i-pre[i])-(i-1-j)>0&&i-1>=j) {
                        dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                    }
                    if(pre[i]-(j-1)>0&&j>0) {
                        dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                    }
                }
                else {
                    if((2*n-pre[n])-(i-1-j)>0&&i-1>=j) {
                        dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                    }
                    if(pre[n]-(j-1)>0&&j>0) {
                        dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                    }
                }
                // printf("%d %d %lld\n",i,j,dp[i][j]);
            }
        }
        printf("%lld\n",dp[2*n][pre[n]]);
    }
    return 0;
}