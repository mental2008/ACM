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
typedef vector<int> vi;

const int inf=0x3f3f3f3f;
const int maxn=5005;
int c[maxn];
int dp[maxn][maxn][2];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&c[i]);
    rep(i,1,n) {
        rep(j,1,n) {
            int l=j,r=j+i-1;
            if(r>n) break;
            rep(sign,0,1) {
                if(i==1) dp[l][r][sign]=0;
                else {
                    int res=inf;
                    if(sign==0) {
                        int temp=(c[l]==c[l+1]?0:1);
                        res=min(res,dp[l+1][r][sign]+temp);
                        temp=(c[l]==c[r]?0:1);
                        res=min(res,dp[l+1][r][sign^1]+temp);
                    }
                    else {
                        int temp=(c[r-1]==c[r]?0:1);
                        res=min(res,dp[l][r-1][sign]+temp);
                        temp=(c[l]==c[r]?0:1);
                        res=min(res,dp[l][r-1][sign^1]+temp);
                    }
                    dp[l][r][sign]=res;
                }
            }
        }
    }
    printf("%d\n",min(dp[1][n][0],dp[1][n][1]));
    return 0;
}