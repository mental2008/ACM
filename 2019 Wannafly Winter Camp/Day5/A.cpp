#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=1005;
int n,m;
vector<int> e[maxn];
int dep[maxn];
int cnt[maxn];
int x[maxn];
int y[maxn];

void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    x[u]=dep[u];
    y[u]=++cnt[dep[u]];
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[0]=0;
    dfs(1,0);
    rep(i,1,n) {
        printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}