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
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=105;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll ans[maxn][maxn];
ll dp[maxn][maxn][maxn][2];
ll a[maxn];
char s[maxn];
int n;

int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,0,maxn-1) {
        rep(j,0,maxn-1) {
            rep(dig,0,1) {
                rep(cnt,0,maxn-1) {
                    int sum=0;
                    rep(k,i,j) {
                        if(s[k]==dig+'0') sum++;
                    }
                    if(sum<cnt) {
                        dp[i][j][cnt][dig]=-INF;
                    }
                }
            }
        }
    }
    rep(i,1,n) {
        rep(j,1,n) {
            int l=j,r=j+i-1;
            if(r>n) continue;
            rep(dig,0,1) {
                rep(cnt,1,i) {
                    int sum=0;
                    rep(k,l,r) if(s[k]==dig+'0') sum++;
                    if(sum<cnt) continue;
                    rep(k,l,r) {
                        if(s[k]==dig+'0') {
                            dp[l][r][cnt][dig]=max(ans[l][k-1]+dp[k+1][r][cnt-1][dig],dp[l][r][cnt][dig]);
                        }
                    }
                    ans[l][r]=max(ans[l][r],dp[l][r][cnt][dig]+a[cnt]);
                }
            }
            rep(dig,0,1) {
                dp[l][r][0][dig]=ans[l][r];
            }
        }
    }
    printf("%lld\n",ans[1][n]);
    return 0;
}