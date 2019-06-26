#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;

const int maxn=1e5+5;
int a[maxn];
vector<int> e[maxn];
int n;
int dep[maxn];
int sum[maxn];
int max_dep;

void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    if(a[u]) max_dep=max(max_dep,dep[u]);
    if(a[u]) sum[dep[u]]++;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    dep[0]=-1;
    max_dep=0;
    dfs(1,0);
    int ans=max_dep;
    rep(i,1,n) {
        ans+=sum[i]-1;
    }
    printf("%d\n",ans);
    return 0;
}