#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<cmath>

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
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n,q;
int pre[maxn];
char s[maxn];

ll quick_pow(ll a,ll m) {
    ll res=1;
    ll p=a;
    while(m) {
        if(m&1) res=res*p%mod;
        p=p*p%mod;
        m>>=1;
    }
    return res;
}

int main() {
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    pre[0]=0;
    rep(i,1,n) {
        pre[i]=pre[i-1]+(s[i]=='1');
    }
    while(q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        ll len=r-l+1;
        ll one=pre[r]-pre[l-1];
        ll zero=len-one;
        ll ans=(quick_pow(2ll,one)-1)%mod;
        ll res=(quick_pow(2ll,one)-1)*(quick_pow(2ll,zero)-1)%mod;
        ans=(ans+res)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}