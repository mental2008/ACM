#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const ll mod=998244353ll;
const int maxn=2005;
int n,m;
char s[maxn][maxn];

int main() {
    scanf("%d%d",&n,&m);
    ll ans=0;
    rep(i,1,n) {
        scanf("%s",s[i]+1);
    }
    rep(i,1,n) {
        rep(j,1,n) {
            if(s[i][j]=='1') {
                ans=(ans+1ll*i*j*(n-i+1)*(m-j+1)%mod)%mod;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}