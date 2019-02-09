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

const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+5;
int cnt[maxn];
ll dp[maxn][3][3];
int n,m;

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        int val;
        scanf("%d",&val);
        cnt[val]++;
    }
    rep(i,0,m+1) {
        rep(j,0,2) {
            rep(k,0,2) {
                dp[i][j][k]=-INF;
            }
        }
    }
    dp[0][0][0]=0;
    rep(i,1,m+1) {
        rep(j,0,2) {
            rep(k,0,2) {
                rep(t,0,2) {
                    if(cnt[i]<j+k+t) continue;
                    dp[i][k][t]=max(dp[i][k][t],dp[i-1][j][k]+t+(cnt[i]-j-k-t)/3);
                }
            }
        }
    }
    printf("%lld\n",dp[m+1][0][0]);
    return 0;
}