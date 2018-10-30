#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=2e5+5;
ll a[maxn];
vector<ll> vec;
int n;
ll t;
ll ans;

void solve(int l,int r) {
    if(l==r) {
        if(a[l]<t) ans++;
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    vec.clear();
    ll res=0;
    rep(i,mid+1,r) {
        res+=a[i];
        vec.push_back(res);
    }
    sort(vec.begin(),vec.end());
    res=0;
    per(i,mid,l) {
        res+=a[i];
        ans+=upper_bound(vec.begin(),vec.end(),t-res-1)-vec.begin();
    }
    return;
}

int main() {
    scanf("%d%lld",&n,&t);
    rep(i,1,n) scanf("%lld",&a[i]);
    ans=0;
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}
