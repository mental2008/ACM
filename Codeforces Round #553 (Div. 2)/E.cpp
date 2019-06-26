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

const int maxn=1e5+5;
int n;
int a[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int m=0;
    ll ans=0;
    rep(i,1,n) {
        if(i==1) {
            ll x=a[i];
            ll y=n-a[i]+1;
            ans+=x*y;
        }
        else if(a[i]==a[i-1]) continue;
        else if(a[i]<a[i-1]) {
            ll x=a[i];
            ll y=a[i-1]-a[i];
            ans+=x*y;
        }
        else {
            ll x=a[i]-a[i-1];
            ll y=n-a[i]+1;
            ans+=x*y;
        }
    }
    printf("%lld\n",ans);
    return 0;
}