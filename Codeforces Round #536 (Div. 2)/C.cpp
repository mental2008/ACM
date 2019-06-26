#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pr(x) cout<<x<<"\n";
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);

const int maxn=3e5+5;
ll a[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll ans=0;
    rep(i,1,n/2) {
        ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}