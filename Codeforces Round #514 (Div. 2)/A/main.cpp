#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n;
ll L,a;

int main() {
    scanf("%d%lld%lld",&n,&L,&a);
    ll now=0;
    ll ans=0;
    rep(i,1,n) {
        ll t,l;
        scanf("%lld%lld",&t,&l);
        ans+=(t-now)/a;
        now=t+l;
    }
    if(L>now) ans+=(L-now)/a;
    printf("%lld\n",ans);
    return 0;
}
