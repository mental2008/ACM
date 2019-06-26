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
typedef vector<int> vi;

map<ll,ll> st;

int main() {
    ll a,b,c,d,e;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
    for(ll i=-50;i<=50;++i) {
        if(i==0) continue;
        for(ll j=-50;j<=50;++j) {
            if(j==0) continue;
            for(ll k=-50;k<=50;++k) {
                if(k==0) continue;
                ll res=a*i*i*i+b*j*j*j+c*k*k*k;
                st[res]++;
            }
        }
    }
    ll ans=0;
    for(ll i=-50;i<=50;++i) {
        if(i==0) continue;
        for(ll j=-50;j<=50;++j) {
            if(j==0) continue;
            ll res=d*i*i*i+e*j*j*j;
            ans+=st[res];
        }
    }
    printf("%lld\n",ans);
    return 0;
}