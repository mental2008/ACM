#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=1e5+5;

ll qpow(ll x,ll n) {
    ll res=1;
    ll p=x;
    while(n) {
        if(n&1) res=(res*p)%10;
        p=(p*p)%10;
        n>>=1;
    }
    return res;
}

int main() {
    ll b,k;
    scanf("%lld%lld",&b,&k);
    ll ans=0;
    per(i,k-1,0) {
        ll a;
        scanf("%lld",&a);
        ll t=qpow(b,i);
        ans=(ans+t*a%10)%10;
    }
    if(ans%2==0) puts("even");
    else puts("odd");
    return 0;
}