#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll mod=998244353ll;
const int maxn=4e5+5;

int n,m;
ll val[maxn];
int fa[maxn];
ll a,b;
int cnt;

ll qpow(ll a,ll x) {
    ll res=1;
    ll p=a;
    while(x) {
        if(x&1) res=res*p%mod;
        p=p*p%mod;
        x>>=1;
    }
    return res;
}

ll find(int x) {
    if(fa[x]==x) return x;
    else {
        ll p=find(fa[x]);
        val[x]=val[fa[x]]*val[x]%mod;
        return fa[x]=p;
    }
}
void connect(int x,int y) {
    int p=++cnt;
    int fa_x=find(x);
    int fa_y=find(y);
    val[fa_x]=a;
    val[fa_y]=b;
    fa[fa_x]=p;
    fa[fa_y]=p;
}

int main() {
    scanf("%d%d",&n,&m);
    ll res=qpow(3ll,n);
    a=qpow(3ll,mod-2);
    b=a*2ll%mod;
    rep(i,0,maxn-1) {
        fa[i]=i;
        val[i]=1;
    }
    cnt=n;
    rep(i,1,m) {
        int o;
        scanf("%d",&o);
        if(o==1) {
            int x,y;
            scanf("%d%d",&x,&y);
            connect(y,x);
        }
        else {
            int x;
            scanf("%d",&x);
            find(x);
            ll ans=res*val[x]%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}