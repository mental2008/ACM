#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,x,y,d;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%lld%lld%lld%lld",&n,&x,&y,&d);
        
        if(abs(x-y)%d==0) {
            printf("%lld\n",abs(x-y)/d);
        }
        else {
            ll p=(x-1+d)/d;
            if((y-1)%d==0) p+=(y-1)/d;
            else p=INF;
            ll q=(n-x+d)/d;
            if((n-y)%d==0) q+=(n-y)/d;
            else q=INF;
            p=min(p,q);
            if(p==INF) puts("-1");
            else printf("%lld\n",p);
        }
    }
    return 0;
}