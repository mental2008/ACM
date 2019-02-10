#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

int main() {
    ll k,a,b;
    while(~scanf("%lld%lld%lld",&k,&a,&b)) {
        if(b-a>2) {
            ll ans=0;
            if((a-1)<=k) {
                k-=(a-1);
                if(k%2) ans++;
                ans+=a+(k/2)*(b-a);
            }
            else {
                ans=k+1;
            }
            printf("%lld\n",ans);
        }
        else {
            ll ans=k+1;
            printf("%lld\n",ans);
        }
    }
    return 0;
}