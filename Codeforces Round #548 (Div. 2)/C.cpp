#include <bits/stdc++.h>

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
typedef vector<int> vi;

const ll mod=1e9+7;
const int maxn=1e5+5;
int n,k;
vector<pii> vec[maxn];
int fa[maxn];
ll sz[maxn];
inline void Add(ll &x,ll y) { x+=y; if(x>=mod) x-=mod; }
ll qpow(ll a,ll n) {
    ll res=1;
    ll p=a;
    while(n) {
        if(n&1) res=res*p%mod;
        p=p*p%mod;
        n>>=1;
    }
    return res;
}
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void connect(int x,int y) {
    int u=find(x);
    int v=find(y);
    if(u!=v) {
        fa[u]=v;
        sz[v]+=sz[u];
    }
}
bool vis[maxn];

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) { fa[i]=i; sz[i]=1; }
    rep(i,1,n-1) {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        if(x==0) connect(u,v);
    }
    ll ans=qpow(n,k);
    rep(i,1,n) {
        int f=find(i);
        if(!vis[f]) {
            vis[f]=1;
            ll res=qpow(sz[f],k);
            ans=(ans-res+mod)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}