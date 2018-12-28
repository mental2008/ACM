#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=10000000000ll;

int main() {
    ll ans=0;
    for(int i=1;i<=1000;++i) {
        ll res=1;
        for(int j=1;j<=i;++j) {
            res=res*i%mod;
        }
        ans=(ans+res)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}