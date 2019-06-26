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
typedef vector<ll> vi;

const ll mod=1e9+7;
const int maxn=1e5+5;
ll m;
vi v;
int cnt;
ll prim[maxn];
bool vis[maxn];
ll sz[maxn];
ll f[maxn];
ll g[maxn];
ll mu[maxn];
void init() {
    mu[1]=1;
    cnt=0;
    rep(i,2,maxn-1) {
        if(!vis[i]) {
            prim[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt&&prim[j]*i<maxn;++j) {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) {
                mu[i*prim[j]]=0;
                break;
            }
            else mu[i*prim[j]]=-mu[i];
        }
    }
}
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
ll inv(ll x) {
    return qpow(x,mod-2);
}
ll calc(ll k) {
    ll temp=inv(m-k);
    ll a=m*k%mod;
    a=a*temp%mod;
    a=a*temp%mod;
    ll b=k*temp%mod;
    a=(a+b)%mod;
    return a;
}

int main() {
    init();
    scanf("%lld",&m);
    rep(i,2,m) {
        sz[i]=0;
        for(int j=i;j<=m;j+=i) sz[i]++;
        // cout<<i<<" "<<sz[i]<<"\n";
        g[i]=calc(sz[i]);
        ll res=(m-sz[i])*inv(m)%mod;
        g[i]=g[i]*res%mod;
        // cout<<i<<" "<<sz[i]<<" "<<g[i]<<"\n";
    }
    rep(i,2,m) {
        f[i]=0;
        for(ll j=i;j<=m;j+=i) {
            ll res=g[j]*mu[j/i]%mod;
            if(res<0) res+=mod;
            f[i]=(f[i]+res)%mod;
        }
    }
    ll ans=inv(m);
    rep(i,2,m) ans=(ans+f[i])%mod;
    // cout<<ans<<"\n";
    // rep(i,2,m) {
    //     ll res=(m-sz[i])*inv(m)%mod;
    //     // cout<<res<<"\n";
    //     res=res*f[i]%mod;
    //     // cout<<res<<"\n";
    //     ans=(ans+res)%mod;
    // }
    printf("%lld\n",ans);
    return 0;
}