#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=1e9+7;
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

int main() {
    ll n;
    scanf("%lld",&n);
    if(n==1) return 0*puts("1");
    ll ans=qpow(3,n-2)*4%mod;
    printf("%lld\n",ans);
    return 0;
}