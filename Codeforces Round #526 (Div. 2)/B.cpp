#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll INF=0x3f3f3f3f;
const int maxn=1005;
ll a[maxn],s;
int n;

int main() {
    scanf("%d%lld",&n,&s);
    ll l=0,r=INF;
    rep(i,1,n) {
        scanf("%lld",&a[i]);
        r=min(r,a[i]);
    }
    ll ans=-1;
    while(l<=r) {
        ll mid=(l+r)>>1;
        ll sum=0;
        rep(i,1,n) {
            if(a[i]>mid) sum+=a[i]-mid;
        }
        if(sum>=s) {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}