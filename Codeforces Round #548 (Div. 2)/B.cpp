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

const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+5;
int n;
ll a[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    ll ans=a[n];
    ll res=a[n];
    per(i,n-1,1) {
        res=min(res-1,a[i]);
        if(res<0) res=0;
        ans+=res;
    }
    printf("%lld\n",ans);
    return 0;
}