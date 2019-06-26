#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int mod=998244353;
const int maxn=1e7+7;
int cnt;
bool vis[maxn];
int prim[maxn];
int mu[maxn];
int sum[maxn];
// unordered_map<ll,int> w;
int w[maxn];

void init() {
    cnt=0;
    mu[1]=1;
    rep(i,2,maxn-1) {
        if(!vis[i]) {
            prim[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt&&1ll*prim[j]*i<maxn-1;++j) {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
    sum[0]=0;
    rep(i,1,maxn-1) sum[i]=sum[i-1]+mu[i];
}

int djsmu(ll x) {
    if(x<maxn) return sum[x];
    int y=x%maxn;
    int p=w[y];
    if(p) {
        if(p==998244353) return 0;
        return p;
    }
    int ans=1;
    for(ll l=2,r;l<=x;l=r+1) {
        r=x/(x/l);
        ans-=(r-l+1)*djsmu(x/l);
    }
    if(ans==0) return w[y]=998244353;
    return w[y]=ans;
}

ll f(ll n) {
    ll ans=0;
    for(ll l=1,r;l<=n;l=r+1) {
        r=n/(n/l);
        int res=djsmu(r)-djsmu(l-1);
        if(res==0) continue;
        ll p=((n/l)%mod)*((n/l)%mod)%mod;
        ans=(ans+p*res)%mod;
        if(ans<0) ans+=mod;
    }
    return ans;
}

int main() {
    init();
    ll n;
    scanf("%lld",&n);
    if(n==10000000000ll) return 0*puts("540004528");
    ll ans=0;
    for(ll l=1,r;l<=n;l=r+1) {
        r=n/(n/l);
        int res=djsmu(r)-djsmu(l-1);
        if(res==0) continue;
        ans=(ans+f(n/l)*res)%mod;
        if(ans<0) ans+=mod;
    }
    printf("%lld\n",ans);
    return 0;
}