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
typedef vector<int> vi;

const int maxn=2e5+5;
int n,m,k;
ll a[maxn];

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n) scanf("%lld",&a[i]);
    ll Max=0;
    rep(i,1,n) Max=max(Max,a[i]);
    int cnt=0;
    rep(i,1,n) if(a[i]==Max) cnt++;
    if(cnt>=2) {
        ll ans=m*Max;
        printf("%lld\n",ans);
    }
    else {
        ll MMax=0;
        rep(i,1,n) {
            if(a[i]==Max) continue;
            MMax=max(MMax,a[i]);
        }
        ll ans=(1ll*m/(k+1))*(Max*k+MMax)+(1ll*(m%(k+1)))*Max;
        printf("%lld\n",ans);
    }
    return 0;
}