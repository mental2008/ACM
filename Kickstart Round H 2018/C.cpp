#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<bitset>

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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=2e5+5;

ll fact[maxn];
ll fiv[maxn];
ll inv[maxn];

void init() {
    fact[0]=fact[1]=1;
    fiv[0]=fiv[1]=1;
    inv[1]=1;
    rep(i,2,maxn-1) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        fiv[i]=inv[i]*fiv[i-1]%mod;
    }
}
ll C(ll x,ll y) {
    if(x<y||y<0) return 0;
    return (fact[x]*fiv[y]%mod)*fiv[x-y]%mod;
}
ll quick_pow(ll a,ll n) {
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
    int caseCnt;
    scanf("%d",&caseCnt);
    rep(T,1,caseCnt) {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=0;
        rep(i,0,m) {
            int sign=(i%2==0?1:-1);
            ll res=C(m,i)*fact[2*n-i]%mod;
            res=res*quick_pow(2,i)%mod;
            ans=(ans+res*sign)%mod;
            if(ans<0) ans+=mod;
        }
        printf("Case #%d: %lld\n",T,ans);
    }
    return 0;
}