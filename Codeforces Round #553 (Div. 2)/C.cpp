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
typedef vector<int> vi;

const ll mod=1e9+7;
ll l,r;
ll two[105];

ll calc(ll x) {
    if(x==0) return 0;
    ll res=1;
    ll p=0;
    for(;res-1<x;res=res*2,p++) ;
    ll ans=0;
    ll n,m;
    if(p%2==0) {
        n=(two[p]-1)/3;
        m=x-n;
    }
    else {
        m=(two[p]-2)/3;
        n=x-m;
    }
    m%=mod;
    ans=(m*(m+1)%mod+ans)%mod;
    n%=mod;
    ans=(n*n%mod+ans)%mod;
    return ans;
}

int main() {
    two[0]=1;
    rep(i,1,100) two[i]=two[i-1]*2;
    scanf("%lld%lld",&l,&r);
    ll ans=(calc(r)-calc(l-1)+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}