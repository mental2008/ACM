#include<bits/stdc++.h>

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
typedef pair<int,int> pii;
const int maxn=2e5+5;
ll h[maxn];
ll cnt[maxn];

int main() {
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    rep(i,1,n) scanf("%lld",&h[i]);
    sort(h+1,h+1+n);
    ll Min=h[1],Max=h[n];
    mem(cnt,0);
    rep(i,1,n) cnt[h[i]]++;
    ll ans=0;
    for(ll i=Max;i>Min;--i) {
        if(cnt[i]==0) continue;
        ans++;
        ll cost=0;
        ll j;
        for(j=i;j>Min;--j) {
            cost+=cnt[j];
            if(cost>k) break;
            cnt[j-1]+=cnt[j];
            cnt[j]=0;
        }
        i=j+1;
    }
    printf("%lld\n",ans);
    return 0;
}
