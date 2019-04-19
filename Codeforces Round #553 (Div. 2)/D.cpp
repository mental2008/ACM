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
struct node {
    ll a,b;
    bool operator<(const node& e) const {
        return (a-b)>(e.a-e.b);
    }
} e[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld%lld",&e[i].a,&e[i].b);
    sort(e+1,e+1+n);
    ll ans=0;
    rep(i,1,n) {
        ans+=e[i].b*n-e[i].a+(e[i].a-e[i].b)*i;
    }
    printf("%lld\n",ans);
    return 0;
}