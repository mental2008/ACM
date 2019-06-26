#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<ll,ll> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

ll gcd(ll x,ll y) {
    return y==0?x:gcd(y,x%y);
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(gcd(a,b)==1) {
            printf("1\n%lld %lld\n",a,b);
            continue;
        }
        vector<pii> va;
        vector<pii> vb;
        if(a%2==0) {
            ll n=a/2;
            va.pb(mp(n-1,n+1));
            va.pb(mp(n+1,n-1));
            va.pb(mp(n,n));
        }
        else {
            ll n=a/2;
            va.pb(mp(n,n+1));
            va.pb(mp(n+1,n));
        }
        if(b%2==0) {
            ll n=b/2;
            vb.pb(mp(n-1,n+1));
            vb.pb(mp(n+1,n-1));
            vb.pb(mp(n,n));
        }
        else {
            ll n=b/2;
            vb.pb(mp(n,n+1));
            vb.pb(mp(n+1,n));
        }
        bool ok=false;
        for(int i=0;i<va.size();++i) {
            for(int j=0;j<vb.size();++j) {
                if(gcd(va[i].fi,vb[j].fi)==1&&gcd(va[i].se,vb[j].se)==1) {
                    ok=true;
                    printf("2\n%lld %lld\n%lld %lld\n",va[i].fi,vb[j].fi,va[i].se,vb[j].se);
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) puts("-1");
    }
    return 0;
}