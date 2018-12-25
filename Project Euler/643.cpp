#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int maxn=3e6+5;
int prim[maxn];
int mu[maxn];
bool vis[maxn];
ll sum[maxn];
unordered_map<ll,ll> w;
ll N=1e11;
int cnt;
void init() {
    mu[1]=1;
    for(int i=2;i<maxn;++i) {
        if(!vis[i]) {
            prim[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt&&1ll*prim[j]*i<maxn;++j) {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
            else mu[prim[j]*i]=-mu[i];
        }
    }
    sum[0]=0;
    for(int i=1;i<maxn;++i) sum[i]=sum[i-1]+mu[i];
}
ll djsmu(ll x) {
    if(x<maxn) return sum[x];
    if(w[x]) return w[x];
    ll ans=1;
    for(ll l=2,r;l<=x;l=r+1) {
        r=x/(x/l);
        ans-=djsmu(x/l)*(r-l+1);
    }
    return w[x]=ans;
}

int main() {
    init();
    ll ans=0;
    ll p=1;
    for(int i=1;;++i) {
        p*=2;
        if(p>N) break;
        for(ll l=1,r;l<=N/p;l=r+1) {
            r=N/p/(N/(l*p));
            ll temp=(N/(l*p))%mod;
            temp=(temp*(temp-1)/2)%mod;
            ll res=((djsmu(r)-djsmu(l-1))*temp)%mod;
            if(res<0) res+=mod;
            ans=(ans+res)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}