#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n=600851475143;
    ll ans=0;
    for(int i=2;i<=3e6;++i) {
        if(n<i) break;
        if(n%i==0) {
            ans=i;
            while(n%i==0) n/=i;
        }
    }
    ans=max(ans,n);
    printf("%lld\n",ans);
    return 0;
}