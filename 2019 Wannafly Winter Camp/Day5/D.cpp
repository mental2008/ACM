#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=10;
int n;
int m[maxn][maxn];
int r[maxn];
int c[maxn];
int dp[(1<<5)-1][20];

bool dfs(int x,int y) {
    // printf("%d %d\n",x,y);
    if(x==n+1) {
        rep(i,1,n) {
            rep(j,1,n) {
                if(m[i][j]==0) putchar('X');
                else putchar('0'+m[i][j]);
            }
            putchar('\n');
        }
        return true;
    }
    // rep(i,1,x-1) {
    //     rep(j,1,n) {
    //         if(m[i][j]==0) putchar('X');
    //         else putchar('0'+m[i][j]);
    //     }
    //     putchar('\n');
    // }
    // rep(j,1,n) {
    //     if(j>=y) putchar('0');
    //     else {
    //         if(m[x][j]==0) putchar('X');
    //         else putchar('0'+m[x][j]);
    //     }
    // }
    // putchar('\n');
    // rep(i,x+1,n) {
    //     rep(j,1,n) putchar('0');
    //     putchar('\n');
    // }
    // puts("");
    set<int> st;
    rep(i,1,n-2) st.insert(i);
    int a=2;
    int p=0;
    int u=(1<<(n-2))-1;
    int o=0;
    rep(i,1,x-1) {
        if(m[i][y]==0) {
            a--;
        }
        else {
            if(a==1) {
                p|=(1<<(m[i][y]-1));
                o+=m[i][y];
            }
            u^=(1<<(m[i][y]-1));
            st.erase(m[i][y]);
        }
    }
    int b=2;
    int q=0;
    int v=(1<<(n-2))-1;
    int t=0;
    rep(i,1,y-1) {
        if(m[x][i]==0) {
            b--;
        }
        else {
            if(b==1) {
                q|=(1<<(m[x][i]-1));
                t+=m[x][i];
            }
            v^=(1<<(m[x][i]-1));
            st.erase(m[x][i]);
        }
    }
    // if(st.empty()) return false;
    if(a>=1&&b>=1) {
        if((a==1&&o!=c[y])||(b==1&&t!=r[x])) {
            ;
        }
        else {
            m[x][y]=0;
            if(y==n) {
                if(dfs(x+1,1)) return true;
            }
            else {
                if(dfs(x,y+1)) return true;
            }
        }
    }
    // puts("fuck");
    // printf("%d %d\n",p|u,c[y]);
    if(dp[p|u][c[y]]==0) return false;
    if(dp[q|v][r[x]]==0) return false;
    // puts("fcuk");
    for(auto it:st) {
        m[x][y]=it;
        if(y==n) {
            if(dfs(x+1,1)) return true;
        }
        else {
            if(dfs(x,y+1)) return true;
        }
    }
    return false;
}

int main() {
    rep(i,0,(1<<5)-1) {
        int res=i;
        for(;res>0;res=(res-1)&i) {
            int p=0;
            rep(j,0,4) {
                if((res>>j)&1) {
                    p+=j+1;
                }
            }
            dp[i][p]=1;
        }
        dp[i][0]=1;
    }
    // rep(i,0,15) cout<<i<<" "<<dp[5][i]<<"\n";
    // return 0;
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        rep(i,1,n) scanf("%d",&r[i]);
        rep(i,1,n) scanf("%d",&c[i]);
        dfs(1,1);
        if(caseCnt!=0) puts("");
    }
    return 0;
}