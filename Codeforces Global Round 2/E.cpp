#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=3e5+5;
int n;
ll a[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    ll ans=0;
    ll pre=0;
    rep(i,1,n) {
        ll temp=min(pre,a[i]/2);
        pre-=temp;
        a[i]-=2ll*temp;
        ans+=temp;
        ans+=a[i]/3;
        pre+=a[i]%3;
    }
    printf("%lld\n",ans);
    return 0;
}