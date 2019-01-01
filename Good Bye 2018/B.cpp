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
typedef pair<ll,ll> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1005;
ll x[maxn];
ll y[maxn];
ll a[maxn];
ll b[maxn];
int n;
multiset<pii> st;

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    rep(i,1,n) {
        scanf("%lld%lld",&a[i],&b[i]);
    }
    rep(i,1,n) {
        ll tx=x[1]+a[i];
        ll ty=y[1]+b[i];
        st.clear();
        // printf("%lld %lld\n",tx,ty);
        rep(j,1,n) {
            if(i==j) continue;
            // printf("add %lld %lld\n",a[j],b[j]);
            st.insert(mp(a[j],b[j]));
        }
        bool ok=true;
        rep(j,2,n) {
            pii p=mp(tx-x[j],ty-y[j]);
            // printf("%lld %lld\n",tx-x[j],ty-y[j]);
            auto pos=st.find(p);
            if(pos!=st.end()) {
                st.erase(*pos);
            }
            else {
                ok=false;
                break;
            }
        }
        // puts("");
        if(ok) {
            printf("%lld %lld\n",tx,ty);
        }
    }
    return 0;
}