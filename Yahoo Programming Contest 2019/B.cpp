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

const int maxn=10;
vector<int> e[maxn];
int dep[maxn];
void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}

int main() {
    rep(i,1,3) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    rep(i,1,4) {
        dep[0]=0;
        dfs(i,0);
        rep(j,1,4) {
            if(dep[j]==4) {
                return 0*puts("YES");
            }
        }
    }
    puts("NO");
    return 0;
}