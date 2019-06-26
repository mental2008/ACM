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
const int maxn=5e5+5;
int n;
int a[maxn];
ll ans;

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    if(a[1]<=0) {
        if(a[n]<=0) {
            ans=0;
            rep(i,1,n-1) {
                if(a[i]<0) ans-=a[i];
                else ans+=a[i];
            }
            ans+=a[n];
        }
        else {
            ans=0;
            rep(i,1,n) {
                if(a[i]<0) ans-=a[i];
                else ans+=a[i];
            }
        }
    }
    else {
        ll sum=0;
        rep(i,1,n) sum+=a[i];
        if(n==1) ans=a[1];
        else ans=sum-2*a[1];
    }
    printf("%lld\n",ans);
    return 0;
}
