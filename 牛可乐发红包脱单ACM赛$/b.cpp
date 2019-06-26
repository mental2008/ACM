#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>

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
const ll mod=1e8+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

ll quick_pow(ll a,ll n) {
    ll res=1;
    ll p=a%mod;
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
    ll inv2=quick_pow(2ll,mod-2);
    ll ans=quick_pow(2ll,n*2);
    ans=(ans+quick_pow(2ll,n+1))%mod;
    ans=(ans+quick_pow(2ll,n))%mod;
    ans=(ans-quick_pow(3ll,n+1)+mod)%mod;
    ans=(ans-1+mod)%mod;
    ans=ans*inv2%mod;
    printf("%lld\n",ans);
    return 0;
}