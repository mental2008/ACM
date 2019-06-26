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
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n,k,m;
ll a[maxn];

int main() {
    scanf("%d%d%d",&n,&k,&m);
    rep(i,1,n) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int j=1;
    ll sum=0;
    int cnt=n;
    rep(i,1,n) sum+=a[i];
    rep(i,1,n-1) {
        if(a[i]*(cnt-1)+cnt-1<=sum-a[i]) {
            j++;
            m--;
            cnt--;
            sum-=a[i];
        }
        else break;
        if(m==0) break;
    }
    ll ans=0;
    rep(i,j,n) ans+=a[i];
    ans+=min(1ll*k*cnt,1ll*m);
    printf("%.10lf\n",(db)ans/cnt);
    return 0;
}