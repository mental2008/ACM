#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll mod=1e9+7;
const int maxn=3e5+5;
int n;
ll a[maxn];
ll vis[maxn];
ll gcd(ll x,ll y) {
    return y==0?x:gcd(y,x%y);
}
bool judge() {
    ll res=0;
    rep(i,1,n) res=gcd(a[i],res);
    return res==1;
}
ll fact[maxn],inv[maxn],fiv[maxn];
void init() {
    fact[0]=fact[1]=1;
    inv[1]=1;
    fiv[0]=fiv[1]=1;
    rep(i,2,maxn-1) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        fiv[i]=fiv[i-1]*inv[i]%mod;
    }
}
ll C(ll m,ll k) {
    if(m<k||k<0) return 0;
    return (fact[m]*fiv[k]%mod)*fiv[m-k]%mod;
}
ll dp[10][maxn];

int main()
{
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%lld",&a[i]);
        vis[a[i]]++;
    }
    bool ok=judge();
    if(!ok) return 0*puts("-1");
    init();
    rep(i,1,maxn-1) {
        for(int j=i*2;j<maxn;j+=i) {
            vis[i]+=vis[j];
        }
    }
    rep(i,1,9) {
        per(j,maxn-1,1) {
            dp[i][j]=C(vis[j],i);
            for(int k=j*2;k<maxn;k+=j) {
                dp[i][j]=(dp[i][j]-dp[i][k]+mod)%mod;
            }
        }
        if(dp[i][1]) return 0*printf("%d\n",i);
    }
    return 0;
}
