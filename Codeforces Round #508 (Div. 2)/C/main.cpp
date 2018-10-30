#include<bits/stdc++.h>
using namespace std;
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;
ll a[maxn];
ll b[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,n) scanf("%lld",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int p=n,q=n;
    ll ans=0;
    while(1) {
        if(p<1&&q<1) break;
        if(p>=1&&q>=1&&a[p]>b[q]) {
            ans+=a[p];
            p--;
        }
        else if(q>=1) {
            q--;
        }
        else {
            ans+=a[p];
            p--;
        }
        if(p<1&&q<1) break;
        if(q>=1&&p>=1&&b[q]>a[p]) {
            ans-=b[q];
            q--;
        }
        else if(p>=1) {
            p--;
        }
        else {
            ans-=b[q];
            q--;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
