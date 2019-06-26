#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int maxn=1e5+5;
int n;
int a[maxn];
int b[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,2*n) {
        int o;
        scanf("%d",&o);
        if(a[o]) b[o]=i;
        else a[o]=i;
    }
    a[0]=b[0]=1;
    ll ans=0;
    rep(i,0,n-1) {
        ans+=min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]),abs(a[i]-b[i+1])+abs(b[i]-a[i+1]));
    }
    printf("%lld\n",ans);
    return 0;
}