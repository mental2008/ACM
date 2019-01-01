#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=998244353ll;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e6+5;
ll n;
ll fact[maxn];
ll inv[maxn];
ll fiv[maxn];
ll sum[maxn];

int main() {
    fact[0]=fact[1]=1;
    inv[1]=1;
    fiv[1]=1;
    sum[1]=1;
    rep(i,2,maxn-1) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        fiv[i]=fiv[i-1]*inv[i]%mod;
        sum[i]=(fiv[i]+sum[i-1])%mod;
    }
    scanf("%lld",&n);
    ll ans=n*fact[n]%mod;
    ll res=fact[n]*sum[n-1]%mod;
    ans=(ans-res+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}