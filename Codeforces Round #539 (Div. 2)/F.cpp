#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const ll mod=1e9+7;
const int maxn=1e6+5;
ll fact[maxn];
ll inv[maxn];
ll fiv[maxn];

void init() {
    fact[0]=fact[1]=1;
    fiv[0]=fiv[1]=1;
    inv[1]=1;
    rep(i,2,maxn-1) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        fiv[i]=fiv[i-1]*inv[i]%mod;
    }
}
ll A(ll n,ll m) {
    return fact[n]*fiv[n-m]%mod;
}
ll C(ll n,ll m) {
    if(n<m||m<0) return 0;
    return (fact[n]*fiv[m]%mod)*fiv[n-m]%mod;
}
ll qpow(ll a,ll n) {
    if(n==-1) return inv[a];
    ll res=1;
    ll p=a;
    while(n) {
        if(n&1) res=res*p%mod;
        p=p*p%mod;
        n>>=1;
    }
    return res;
}

int main() {
    init();
    ll n,m,a,b;
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    ll ans=0;
    for(ll i=1;i<=n-1;++i) {
        ll res=(((A(n-2,i-1)*C(m-1,i-1)%mod)*qpow(m,n-1-i)%mod)*qpow(n,n-i-2)%mod)*(i+1)%mod;
        ans=(ans+res)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}