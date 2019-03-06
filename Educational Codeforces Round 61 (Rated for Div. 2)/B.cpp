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

const int maxn=3e5+5;
ll a[maxn];
ll b[maxn];
int n;
int m;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    ll sum=0;
    rep(i,1,n) sum+=a[i];
    sort(a+1,a+1+n);
    scanf("%d",&m);
    rep(i,1,m) {
        scanf("%lld",&b[i]);
        ll ans=sum-a[n-b[i]+1];
        printf("%lld\n",ans);
    }
    return 0;
}