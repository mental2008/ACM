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

const int maxn=505;
int n,m;
int a[maxn][maxn];
struct node {
    int pos;
    bool flag;
} dp[maxn][1200];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
    rep(i,0,n) {
        rep(j,0,1023) {
            dp[i][j].flag=false;
        }
    }
    dp[0][0].flag=true;
    rep(i,1,n) {
        rep(j,0,1023) {
            if(!dp[i-1][j].flag) continue;
            rep(k,1,m) {
                if(dp[i][j^a[i][k]].flag) continue;
                dp[i][j^a[i][k]].flag=true;
                dp[i][j^a[i][k]].pos=k;
            }
        }
    }
    rep(i,1,1023) {
        if(dp[n][i].flag) {
            vi v;
            int res=i;
            per(j,n,1) {
                // printf("%d\n",dp[j][res].pos);
                v.pb(dp[j][res].pos);
                res^=a[j][dp[j][res].pos];
            }
            puts("TAK");
            per(j,n-1,0) {
                printf("%d%c",v[j],i==0?'\n':' ');
            }
            return 0;
        }
    }
    puts("NIE");
    return 0;
}