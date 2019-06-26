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

const int maxn=2e5+5;
int n,m;
vector<int> e[maxn];
struct Edge {
    int u,v;
} edge[300005];
bool vis[maxn];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
        vis[u]=vis[v]=1;
        edge[i].u=u;
        edge[i].v=v;
    }
    bool ok=true;
    rep(i,1,m) {
        int a=e[edge[i].u].size();
        int b=e[edge[i].v].size();
        if(a>1&&b>1) {
            ok=false;
            break;
        }
    }
    rep(i,1,n) {
        if(!vis[i]) {
            ok=false;
            break;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}