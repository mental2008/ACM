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
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(m==0) {
        printf("%lld %lld\n",n,n);
        return 0;
    }
    ll Min;
    if(2*m>=n) Min=0;
    else Min=n-2*m;
    ll Max=0;
    for(ll i=1;i<=n;++i) {
        ll sum=i*(i-1)/2;
        if(sum>=m) {
            Max=n-i;
            break;
        }
    }
    printf("%lld %lld\n",Min,Max);
    return 0;
}
