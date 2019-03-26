#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll mod=998244353ll;
const int maxn=2e5+5;
int n;
ll k;
ll qpow(ll a,ll n) {
    ll res=1;
    ll p=a;
    while(n) {
        if(n&1) res=res*p%mod;
        p=p*p%mod;
        n>>=1;
    }
    return res;
}
ll f[maxn][2];
ll a[maxn];

int main() {
    scanf("%d%lld",&n,&k);
    rep(i,1,n) scanf("%lld\n",&a[i]);
    // cout<<a[1]<<" "<<a[2]<<"\n";
    a[n+1]=a[n+2]=k+1;
    f[1][0]=k-1;
    rep(i,2,maxn-1) f[i][0]=(qpow(k-1,i)-f[i-1][0]+mod)%mod;
    f[1][1]=k-2;
    rep(i,2,maxn-1) f[i][1]=(qpow(k-1,i)-f[i-1][1]+mod)%mod;
    ll num=0;
    ll l=k+1,r;
    ll ans=1;
    for(int i=1;i<=n+2;i+=2) {
        if(a[i]==-1) num++;
        else {
            if(num==0) { 
                if(a[i]==l&&l!=k+1) ans=0;
                l=a[i]; continue;
            }
            r=a[i];
            if(l==k+1) {
                if(r==k+1) ans=(ans*k%mod)*qpow(k-1,num-1)%mod;
                else ans=ans*qpow(k-1,num)%mod;
            }
            else {
                if(r==k+1) ans=ans*qpow(k-1,num)%mod;
                else ans=ans*f[num][l!=r]%mod;
            }
            l=a[i];
            num=0;
        }
    }
    l=k+1,r;
    num=0;
    for(int i=2;i<=n+2;i+=2) {
        if(a[i]==-1) num++;
        else {
            if(num==0) { 
                if(a[i]==l&&l!=k+1) ans=0;
                l=a[i]; continue;
            }
            r=a[i];
            if(l==k+1) {
                if(r==k+1) ans=(ans*k%mod)*qpow(k-1,num-1)%mod;
                else ans=ans*qpow(k-1,num)%mod;
            }
            else {
                if(r==k+1) ans=ans*qpow(k-1,num)%mod;
                else ans=ans*f[num][l!=r]%mod;
            }
            l=a[i];
            num=0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}