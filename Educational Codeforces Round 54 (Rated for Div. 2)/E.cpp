#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=3e5+5;

int n,m;
ll val[maxn];
vector<int> e[maxn];
vector<int> dep[maxn];
vector<ll> cha[maxn];
int dfs_clock;
int in[maxn];
int out[maxn];
int cc[maxn];
int max_depth;
int son_dep[maxn];
int height[maxn];

void dfs(int u,int fa,int depth) {
    in[u]=++dfs_clock;
    cc[dfs_clock]=u;
    dep[depth].pb(dfs_clock);
    cha[depth].pb(0);
    max_depth=max(max_depth,depth);
    height[u]=depth;
    son_dep[u]=depth;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u,depth+1);
        son_dep[u]=max(son_dep[u],son_dep[v]);
    }
    out[u]=dfs_clock;
}
void dfs2(int u,int fa) {
    val[u]+=val[fa];
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs2(v,u);
    }
}

int main() {
    scanf("%d",&n);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    mem(val,0);
    dfs_clock=0;
    max_depth=0;
    mem(son_dep,0);
    dfs(1,0,0);
    scanf("%d",&m);
    while(m--) {
        int u;
        ll k,x;
        scanf("%d%lld%lld",&u,&k,&x);
        val[u]+=x;
        // cout<<u<<" "<<height[u]<<" "<<k<<"\n";
        if(son_dep[u]-height[u]>k) {
            int d=height[u]+k+1;
            // cout<<"fuck "<<d<<"\n";
            int p=lower_bound(dep[d].begin(),dep[d].end(),in[u])-dep[d].begin();
            int q=upper_bound(dep[d].begin(),dep[d].end(),out[u])-dep[d].begin();
            cha[d][p]-=x;
            int len=dep[d].size();
            if(q==len) continue;
            cha[d][q]+=x;
        }
    }
    rep(i,0,max_depth) {
        int len=dep[i].size();
        rep(j,0,len-1) {
            if(j!=0) cha[i][j]+=cha[i][j-1];
            val[cc[dep[i][j]]]+=cha[i][j];
            // cout<<cc[dep[i][j]]<<" "<<cha[i][j]<<"\n";
        }
    }
    dfs2(1,0);
    rep(i,1,n) {
        printf("%lld%c",val[i],(i==n?'\n':' '));
    }
    return 0;
}