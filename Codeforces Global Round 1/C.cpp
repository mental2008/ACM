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

ll gcd(ll x,ll y) {
    return y==0?x:gcd(y,x%y);
}

ll b[]={1,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int main() {
    int q;
    scanf("%d",&q);
    while(q--) {
        ll a;
        scanf("%lld",&a);
        int ans=0;
        bool ok=true;
        while(a) {
            ans++;
            if(!(a&1)) ok=false;
            a>>=1;
        }
        if(!ok) printf("%lld\n",(1ll<<ans)-1);
        else {
            printf("%lld\n",b[ans-1]);
        }
    }
    return 0;
}