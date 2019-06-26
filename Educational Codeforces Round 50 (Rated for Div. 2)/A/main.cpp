#include <bits/stdc++.h>
using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double exps=1e-8;
const double pi=acos(-1.0);
const int maxn=1e5+5;
ll n,k;

int main() {
    scanf("%lld%lld",&n,&k);
    ll l=1,r=k/n+1;
    ll ans;
    while(l<=r) {
        ll mid=(l+r)>>1;
        if((mid-1)*n+1<=k&&k<=mid*n) {
            ans=mid;
            break;
        }
        if(k>mid*n) {
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
