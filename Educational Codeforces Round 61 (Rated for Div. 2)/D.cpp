#include <bits/stdc++.h>

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
typedef vector<int> vi;

const ll INF=1e11;
const int maxn=2e5+5;
int n,k;
ll a[maxn];
ll ta[maxn];
ll temp[maxn];
ll b[maxn];

bool solve(ll m) {
    rep(i,1,n) ta[i]=a[i];
    int t=0;
    while(t<k) {
        int tl=t+1,tr=k-1;
        if(tl>tr) break;
        int last=t;
        t=t+1;
        while(tl<=tr) {
            int mid=(tl+tr)>>1;
            bool ok=false;
            rep(i,1,n) {
                temp[i]=ta[i]-b[i]*mid;
                // cout<<i<<" "<<temp[i]<<"\n";
                if(temp[i]<0) {
                    ok=true;
                    break;
                }
            }
            if(ok) {
                t=mid;
                tr=mid-1;
            }
            else tl=mid+1;
        }
        cout<<"t = "<<t<<"\n";
        rep(i,1,n) {
            cout<<i<<" "<<ta[i]-b[i]*t<<"\n";
        }
        // cout<<"last = "<<last<<"\n";
        // if(t==last) return true;
        int tt=last;
        rep(i,1,n) {
            temp[i]=ta[i]-b[i]*t;
            if(temp[i]<0) {
                // m*k>=b[i]*t-ta[i]
                int k=(b[i]*t-ta[i])/m;
                ta[i]+=m*k;
                tt+=k;
            }
        }
        if(tt>t) return false;
        t=tt;
    }
    return true;
}

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,n) scanf("%lld",&b[i]);

    // cout<<solve(5)<<"\n";
    // return 0;

    ll l=0,r=INF;
    ll ans=-1;
    while(l<=r) {
        ll mid=(l+r)>>1;
        if(solve(mid)) {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}