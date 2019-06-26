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

const int maxn=2e5+5;
int n;
ll a[maxn];
vector<ll> vp,vn;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    
    ll ans=0;
    rep(i,1,n) if(a[i]>0) vp.pb(a[i]);
    sort(vp.begin(),vp.end());
    int lenp=(int)vp.size();
    rep(i,1,n) if(a[i]<0) vn.pb(a[i]);
    sort(vn.begin(),vn.end());
    int lenn=(int)vn.size();
    
    rep(i,0,lenp-1) {
        auto p1=upper_bound(vp.begin(),vp.end(),vp[i]*2); p1--;
        auto p2=upper_bound(vp.begin(),vp.end(),vp[i]);
        int res=(p1-p2+1);
        if(res>0) ans+=res;
        p1=lower_bound(vn.begin(),vn.end(),-vp[i]); p1--;
        p2=lower_bound(vn.begin(),vn.end(),-vp[i]*2);
        res=(p1-p2+1);
        if(res>0) ans+=res;
    } // positive

    rep(i,0,lenn-1) {
        auto p1=upper_bound(vp.begin(),vp.end(),-vn[i]*2); p1--;
        auto p2=lower_bound(vp.begin(),vp.end(),-vn[i]);
        int res=(p1-p2+1);
        if(res>0) ans+=res;
        p1=lower_bound(vn.begin(),vn.end(),vn[i]); p1--;
        p2=lower_bound(vn.begin(),vn.end(),vn[i]*2);
        res=(p1-p2+1);
        if(res>0) ans+=res;
    } // negative

    printf("%lld\n",ans);
    return 0;
}