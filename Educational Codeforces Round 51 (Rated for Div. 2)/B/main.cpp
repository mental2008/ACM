#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int maxn=1e5+5;

int main() {
    ll l,r;
    scanf("%lld%lld",&l,&r);
    puts("YES");
    for(ll i=l;i<=r;i+=2) {
        printf("%lld %lld\n",i,i+1);
    }
    return 0;
}
