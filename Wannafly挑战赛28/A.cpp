#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;

int main() {
    ll a,b,L;
    while(~scanf("%lld%lld%lld",&a,&b,&L)) {
        ll x=a,y=b;
        int t=0;
        while(1) {
            if(x>L) break;
            ll y0=y;
            while(y<y0*2) y+=x;
            t^=1;
            swap(x,y);
        }
        if(t) printf("No ");
        else printf("Yes ");
        x=b,y=a;
        t=1;
        while(1) {
            if(x>L) break;
            ll y0=y;
            while(y<y0*2) y+=x;
            t^=1;
            swap(x,y);
        }
        if(t) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}