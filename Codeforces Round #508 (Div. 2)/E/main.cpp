#include<bits/stdc++.h>
using namespace std;
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=105;
int n;
ll dp[maxn][maxn][5][5];
int c1[maxn];
int c2[maxn];
ll val[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d%lld%d",&c1[i],&val[i],&c2[i]);
    }
    mem(dp,0);
    ll ans=0;
    rep(i,1,n) {
        rep(j,1,n) {
            if(j+i-1>n) break;
            if(i==1) {
                dp[j][j][c1[j]][c2[j]]=val[j];
                dp[j][j][c2[j]][c1[j]]=val[j];
            }
            else {
                rep(l,1,4) rep(p,1,4) dp[j][j+i-1][l][p]=max(dp[j][j+i-2][l][p],dp[j+1][j+i-1][l][p]);
                rep(k,j,j+i-1) {
                    rep(l,1,4) {
                        rep(p,1,4) {
                            if(k==j) {
                                if(l==c1[j]&&dp[j+1][j+i-1][c2[k]][p]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],val[k]+dp[j+1][j+i-1][c2[k]][p]);
                                if(l==c2[j]&&dp[j+1][j+i-1][c1[k]][p]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],val[k]+dp[j+1][j+i-1][c1[k]][p]);
                                if(p==c1[j]&&dp[j+1][j+i-1][c2[k]][l]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],val[k]+dp[j+1][j+i-1][c2[k]][l]);
                                if(p==c2[j]&&dp[j+1][j+i-1][c1[k]][l]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],val[k]+dp[j+1][j+i-1][c1[k]][l]);
                                continue;
                            }
                            else if(k==j+i-1) {
                                if(l==c1[k]&&dp[j][j+i-2][p][c2[k]]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][j+i-2][p][c2[k]]+val[k]);
                                if(l==c2[k]&&dp[j][j+i-2][p][c1[k]]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][j+i-2][p][c1[k]]+val[k]);
                                if(p==c1[k]&&dp[j][j+i-2][l][c2[k]]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][j+i-2][l][c2[k]]+val[k]);
                                if(p==c2[k]&&dp[j][j+i-2][l][c1[k]]) dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][j+i-2][l][c1[k]]+val[k]);
                                continue;
                            }
                            if(dp[j][k-1][l][c1[k]]&&dp[k+1][j+i-1][c2[k]][p])
                                dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][l][c1[k]]+val[k]+dp[k+1][j+i-1][c2[k]][p]);
                            if(dp[j][k-1][p][c1[k]]&&dp[k+1][j+i-1][c2[k]][l])
                                dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][p][c1[k]]+val[k]+dp[k+1][j+i-1][c2[k]][l]);
                            if(dp[j][k-1][l][c2[k]]&&dp[k+1][j+i-1][c1[k]][p])
                                dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][l][c2[k]]+val[k]+dp[k+1][j+i-1][c1[k]][p]);
                            if(dp[j][k-1][p][c2[k]]&&dp[k+1][j+i-1][c1[k]][l])
                                dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][p][c2[k]]+val[k]+dp[k+1][j+i-1][c1[k]][l]);

                            rep(q,1,4) {
                                if(p==c2[k]&&dp[j][k-1][l][q]&&dp[k+1][j+i-1][q][c1[k]])
                                    dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][l][q]+dp[k+1][j+i-1][q][c1[k]]+val[k]);
                                if(p==c1[k]&&dp[j][k-1][l][q]&&dp[k+1][j+i-1][q][c2[k]])
                                    dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][l][q]+dp[k+1][j+i-1][q][c2[k]]+val[k]);
                                if(l==c2[k]&&dp[j][k-1][p][q]&&dp[k+1][j+i-1][q][c1[k]])
                                    dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][p][q]+dp[k+1][j+i-1][q][c1[k]]+val[k]);
                                if(l==c1[k]&&dp[j][k-1][p][q]&&dp[k+1][j+i-1][q][c2[k]])
                                    dp[j][j+i-1][l][p]=max(dp[j][j+i-1][l][p],dp[j][k-1][p][q]+dp[k+1][j+i-1][q][c2[k]]+val[k]);
                            }

                        }
                    }
                }
            }
        }
    }
    rep(l,1,4) rep(p,1,4) ans=max(ans,dp[1][n][l][p]);
    /*rep(i,1,n) {
        rep(j,1,n) {
            if(j+i-1>n) break;
            rep(l,1,4) {
                rep(p,1,4) {
                    printf("l = %d, r = %d, head = %d, tail = %d, val = %lld\n",j,j+i-1,l,p,dp[j][j+i-1][l][p]);
                }
            }
        }
    }*/
    printf("%lld\n",ans);
    return 0;
}
