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
const ll mod=1e9+7;
const int maxn=1005;
ll a[maxn],b[maxn];
int n,m;
ll w,h;
bitset<maxn> st[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%lld%lld%d%d",&w,&h,&n,&m);
        rep(i,0,n-1) scanf("%lld",&a[i]);
        rep(i,0,m-1) scanf("%lld",&b[i]);
        rep(i,0,n-1) st[i].reset();
        rep(i,0,n-1) {
            rep(j,0,m-1) {
                ll x=a[i]+b[j],y=a[i]-b[j];
                if(x>=0&&x<=w*2&&y>=0&&y<=h*2) {
                    st[i].set(j);
                }
            }
        }
        ll ans=0;
        rep(i,0,n-1) {
            rep(j,i+1,n-1) {
                bitset<maxn> temp=(st[i]&st[j]);
                ll res=(ll)temp.count();
                res=res*(res-1)/2;
                ans=(ans+res)%mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
x=(a[i]+b[i]);
y=(a[i]-b[i]);
0≤x≤w*2
0≤y≤h*2
*/