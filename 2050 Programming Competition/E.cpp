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

const int maxn=10005;
char s[maxn];
int dp[maxn][11][11];

struct node {
    int x,y,z;
    node() {}
    node(int x,int y,int z):x(x),y(y),z(z) {}
};
node solve(int a,int b) {
    node temp;
    if(a==11||b==11) {
        return node(0,0,1);
    }
    if(a==10&&b==10) {
        return node(9,9,0);
    }
    return node(a,b,0);
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%s",s+1);
        int n=strlen(s+1);
        mem(dp,-0x3f);
        dp[0][0][0]=0;
        rep(i,1,n) {
            rep(j,0,10) {
                rep(k,0,10) {
                    if(s[i]=='A'||s[i]=='?') {
                        node temp=solve(j+1,k);
                        dp[i][temp.x][temp.y]=max(dp[i][temp.x][temp.y],dp[i-1][j][k]+temp.z);
                    }
                    if(s[i]=='B'||s[i]=='?') {
                        node temp=solve(j,k+1);
                        dp[i][temp.x][temp.y]=max(dp[i][temp.x][temp.y],dp[i-1][j][k]+temp.z);
                    }
                }
            }
        }
        int ans=0;
        rep(i,0,10) rep(j,0,10) ans=max(ans,dp[n][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}