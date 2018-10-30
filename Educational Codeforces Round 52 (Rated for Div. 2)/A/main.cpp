#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll s,a,b,c;
        scanf("%lld%lld%lld%lld",&s,&a,&b,&c);
        ll k=s/(a*c);
        s-=k*a*c;
        ll ans=k*(a+b)+s/c;
        printf("%lld\n",ans);
    }
    return 0;
}
