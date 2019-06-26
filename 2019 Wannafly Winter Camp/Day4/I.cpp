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

const int maxn=1005;
ll a[maxn];
ll b[maxn];
ll res[maxn];
int n;

ll solve(ll x) {
    ll p=0;
    rep(i,1,n) p+=a[i];
    rep(i,1,n) res[i]=-a[i]+b[i]*x;
    sort(res+1,res+1+n);
    per(i,n,x+1) {
        p+=res[i];
    }
    return p;
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld%lld",&a[i],&b[i]);
    ll ans=0;
    int l=1,r=n;
    while(l<=r) {
        ll len=(r-l)/3;
        ll ql=l+len;
        ll qr=r-len;
        ll xx=solve(ql);
        ll yy=solve(qr);
        if(xx<=yy) {
            l=ql+1;
        }
        else {
            r=qr-1;
        }
        ans=max(ans,xx);
        ans=max(ans,yy);
    }
    printf("%lld\n",ans);
    return 0;
}