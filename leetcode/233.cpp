#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt[20];
int dp[20][12];
int dfs(int depth,int one,bool flag) {
    if(depth==-1) return one;
    if(!flag&&dp[depth][one]!=-1) return dp[depth][one];
    int p=flag?cnt[depth]:9;
    int res=0;
    for(int i=0;i<=p;++i) {
        res+=dfs(depth-1,one+(i==1),flag&&i==p);
    }
    if(!flag) dp[depth][one]=res;
    return res;
}

int countDigitOne(int n) {
    int i=0;
    while(n) {
        cnt[i++]=n%10;
        n/=10;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(i-1,0,1);
}

int main() {
    printf("%d\n",countDigitOne(13));
    return 0;
}