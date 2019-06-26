#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=505;
int dp[maxn][maxn][27];
char s[maxn];
int n;

int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    mem(dp,0x3f);
    rep(i,1,n) dp[i][i][s[i]-'a']=0;
    rep(i,1,n) {
        rep(j,1,n) {
            int l=j,r=j+i-1;
            if(r>n) break;
            rep(t,0,25) {
                rep(k,l,r) {
                    dp[l][r][t]=min(dp[l][k][t]+dp[k+1][r][t],dp[l][r][t]);
                    dp[l][r][t]=min(dp[l][k][26]+dp[k+1][r][t],dp[l][r][t]);
                    dp[l][r][t]=min(dp[l][k][t]+dp[k+1][r][26],dp[l][r][t]);
                }
                dp[l][r][26]=min(dp[l][r][26],dp[l][r][t]+1);
            }
            rep(k,l,r) {
                dp[l][r][26]=min(dp[l][k][26]+dp[k+1][r][26],dp[l][r][26]);
            }
        }
    }
    printf("%d\n",dp[1][n][26]);
    return 0;
}