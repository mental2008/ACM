#include <bits/stdc++.h>

using namespace std;

const int n=1000;
int dp[n+5][n+5][n+5];

int dfs(int x,int y,int z) {
    if((x&&y==0&&z==0)||(x==0&&y&&z==0)||(x==0&&y==0&&z)) return dp[x][y][z]=1;
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    if(x>0) {
        for(int i=1;i<=x;++i) {
            if(!dfs(x-i,y,z)) {
                return dp[x][y][z]=1;
            }
        }
    }
    if(y>0) {
        for(int i=1;i<=y;++i) {
            if(!dfs(x,y-i,z)) {
                return dp[x][y][z]=1;
            }
        }
    }
    if(z>0) {
        for(int i=1;i<=z;++i) {
            if(!dfs(x,y,z-i)) {
                return dp[x][y][z]=1;
            }
        }
    }
    if(x>0&&y>0) {
        for(int i=1;i<=min(x,y);++i) {
            if(!dfs(x-i,y-i,z)) {
                return dp[x][y][z]=1;
            }
        }
    }
    if(x>0&&z>0) {
        for(int i=1;i<=min(x,z);++i) {
            if(!dfs(x-i,y,z-i)) {
                return dp[x][y][z]=1;
            }
        }
    }
    if(y>0&&z>0) {
        for(int i=1;i<=min(y,z);++i) {
            if(!dfs(x,y-i,z-i)) {
                return dp[x][y][z]=1;
            }
        }
    }
    if(x>0&&y>0&&z>0) {
        for(int i=1;i<=min(x,min(y,z));++i) {
            if(!dfs(x-i,y-i,z-i)) {
                return dp[x][y][z]=1;
            }
        }
    }
    return dp[x][y][z]=0;
}

int main() {
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    int ans=0;
    for(int x=0;x<=n;++x) {
        for(int y=x;y<=n;++y) {
            for(int z=y;z<=n;++z) {
                if(dfs(x,y,z)==0) {
                    cout<<x<<" "<<y<<" "<<z<<"\n";
                    ans+=x+y+z;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}