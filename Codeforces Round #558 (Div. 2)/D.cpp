#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inf=0x3f3f3f3f;
const int maxn=1005;
const int N=55;
const int M=55;
char c[maxn];
int len;
char s[N],t[M];
int n,m;
int nxt_s[N],nxt_t[M];
int tr_s[N][26],tr_t[M][26];
int dp[maxn][N][M];
void kmp(char s[],int k,int next[],int tr[][26]) {
    next[1]=0;
    rep(i,2,k) {
        int cur=next[i-1];
        while(cur!=0&&s[cur+1]!=s[i]) cur=next[cur];
        if(s[cur+1]==s[i]) cur++;
        next[i]=cur;
    }
    rep(i,0,k) {
        rep(j,0,25) {
            int cur=i;
            while(cur!=0&&s[cur+1]!='a'+j) cur=next[cur];
            if(s[cur+1]=='a'+j) cur++;
            tr[i][j]=cur;
        }
    }
}

int main() {
    scanf("%s%s%s",c+1,s+1,t+1);
    len=strlen(c+1); n=strlen(s+1); m=strlen(t+1);
    kmp(s,n,nxt_s,tr_s); kmp(t,m,nxt_t,tr_t);
    mem(dp,-inf); dp[0][0][0]=0;
    rep(i,0,len-1) {
        rep(j,0,n) {
            rep(k,0,m) {
                rep(p,0,25) {
                    if(c[i+1]=='*'||c[i+1]=='a'+p) {
                        int res=dp[i][j][k]+(tr_s[j][p]==n)-(tr_t[k][p]==m);
                        dp[i+1][tr_s[j][p]][tr_t[k][p]]=max(dp[i+1][tr_s[j][p]][tr_t[k][p]],res);
                    }
                }
            }
        }
    }
    int ans=-inf;
    rep(i,0,n) {
        rep(j,0,m) {
            ans=max(dp[len][i][j],ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}