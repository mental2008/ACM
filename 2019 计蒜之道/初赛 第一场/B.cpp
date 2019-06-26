#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

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

const ll mod=1e9+7;
const int maxn=1005;
int n,m;
vector<pii> e[maxn];
vector<pii> g[maxn];
int a[maxn][maxn];

int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
void Add(int &x,int y) { x+=y; if(x>=mod) x-=mod; }
void dfs(int u,int fa) {
    for(auto p:e[u]) {
        int v=p.fi;
        if(v==fa) continue;
        dfs(v,u);
    }
    if((int)e[u].size()==1) {
        rep(i,1,m) {
            g[u].pb(mp(i,1ll));
        }
    }
    else {
        rep(i,1,m) {
            int res=1;
            for(auto p:e[u]) {
                int v=p.fi;
                if(v==fa) continue;
                int w=p.se;
                int temp=0;
                for(auto t:g[v]) {
                    if(a[t.fi][i]==w) continue;
                    Add(temp,t.se);
                }
                res=(1ll*res*temp)%mod;
                if(res==0) break;
            }
            if(res==0) continue;
            g[u].pb(mp(i,res));
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,m) rep(j,1,m) a[i][j]=gcd(i,j);
    rep(i,1,n-1) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].pb(mp(v,w));
        e[v].pb(mp(u,w));
    }
    e[1].pb(mp(0,0));
    dfs(1,0);
    int ans=0;
    for(auto t:g[1]) {
        Add(ans,t.se);
    }
    printf("%d\n",ans);
    return 0;
}