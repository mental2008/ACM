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
ll s[maxn];
int n;
ll d[maxn];
ll sum[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&s[i]);
    sort(s+1,s+1+n);
    n=unique(s+1,s+1+n)-s-1;
    rep(i,1,n-1) {
        d[i]=s[i+1]-s[i]-1;
    }
    sort(d+1,d+n);
    sum[0]=0;
    rep(i,1,n-1) sum[i]=sum[i-1]+d[i];
    int q;
    scanf("%d",&q);
    while(q--) {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        int pos=lower_bound(d+1,d+n,r-l)-d-1;
        ll ans=n+sum[pos]+(r-l)*(n-pos);
        printf("%lld ",ans);
    }
    puts("");
    return 0;
}