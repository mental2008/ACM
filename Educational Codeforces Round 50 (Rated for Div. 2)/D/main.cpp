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
const int maxn=3e5+5;
int n,m;
ll a[maxn];
ll b[maxn];
ll pa[maxn];
ll pb[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    pa[0]=0;
    rep(i,1,n) pa[i]=pa[i-1]+a[i];
    scanf("%d",&m);
    rep(i,1,m) scanf("%lld",&b[i]);
    pb[0]=0;
    rep(i,1,m) pb[i]=pb[i-1]+b[i];
    int res=0;
    int lst=0;
    int fb=0;
    for(int i=1;i<=n;++i) {
        int l=fb+1,r=m;
        ll ta=pa[i]-pa[lst];
        bool ok=false;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(pb[mid]-pb[fb]==ta) {
                ok=true;
                res++;
                lst=i;
                fb=mid;
                break;
            }
            if(pb[mid]-pb[fb]>ta) r=mid-1;
            else l=mid+1;
        }
        if(!ok&&i==n) {
            return 0*puts("-1");
        }
    }
    if(fb==m) printf("%d\n",res);
    else puts("-1");
    return 0;
}
