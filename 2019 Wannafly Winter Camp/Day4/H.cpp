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
const int maxn=55;
db f[505][10][55];
db g[505][10][55];
db pre[55];
int n;
db p[10][10];
db ans[10];

int main() {
    scanf("%d",&n);
    rep(i,1,6) {
        rep(j,1,6) {
            scanf("%lf",&p[i][j]);
        }
    }
    rep(i,1,6) g[0][i][0]=1.0;
    rep(i,0,n-1) pre[i]=1.0;
    rep(i,1,500) {
        rep(j,1,6) {
            rep(k,0,n-1) {
                rep(l,1,6) {
                    g[i][j][k]+=g[i-1][j][(k-l+n)%n]*p[j][l];
                }
                f[i][j][k]=g[i][j][k];
                f[i][j][k]*=pre[k];
                ans[j]+=f[i][j][k];
                pre[k]*=(1-g[i][j][k]);
                // rep(l,1,i) {
                //     rep(o,1,6) {
                //         if(l==i&&o==j) break;
                //         f[i][j][k]*=(1-g[l][o][k]);
                //     }
                // }
            }
        }
    }
    rep(i,1,6) {
        printf("%.3lf\n",ans[i]);
    }
    return 0;
}