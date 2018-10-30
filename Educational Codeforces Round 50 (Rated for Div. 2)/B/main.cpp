#include <bits/stdc++.h>
using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double exps=1e-8;
const double pi=acos(-1.0);
const int maxn=1e5+5;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        if(n>m) swap(n,m);
        if(m>k) puts("-1");
        else {
            ll ans=n;
            if((m-n)%2==0) {
                ans+=(m-n);
                ll res=k-m;
                if(res%2==0) ans+=res;
                else {
                    res--;
                    ans--;
                    ans+=res;
                }
            }
            else {
                ans+=(m-n-1);
                ll res=k-m+1;
                if(res%2==0) {
                    res-=2;
                    ans++;
                    ans+=res;
                }
                else {
                    res--;
                    ans+=res;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
