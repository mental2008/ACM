#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const ll INF=0x3f3f3f3f;
ll n;
ll k;

int main() {
    scanf("%lld%lld",&n,&k);
    ll x=INF;
    for(ll i=1;i*i<=n;++i) {
        if(n%i==0) {
            ll p=i;
            ll q=n/i;
            ll res;
            if(q<k) {
                res=p*k+q;
                x=min(res,x);
            }
            if(p<k) {
                res=q*k+p;
                x=min(res,x);
            }
        }
    }
    printf("%lld\n",x);
    return 0;
}