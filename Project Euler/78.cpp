#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=1000000;

int main() {
    ll res=1;
    ll sum=0;
    int cnt=1;
    while(1) {
        res=(sum+1)%mod;
        cnt++;
        printf("%lld %d\n",res,cnt);
        if(res==0) break;
        sum=(sum+res)%mod;
        if(cnt==5) break;
    }
    printf("%d\n",cnt);
    return 0;
}