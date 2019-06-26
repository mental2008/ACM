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
typedef vector<int> vi;

const ll mod=1e9+7;
const int maxn=105;
ll fact[maxn];
ll fiv[maxn];
ll inv[maxn];
void init() {
    fact[0]=fact[1]=1;
    fiv[0]=fiv[1]=1;
    inv[1]=1;
    for(int i=2;i<maxn;++i) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        fiv[i]=fiv[i-1]*inv[i]%mod;
    }
}
ll C(ll m,ll k) {
    if(m<k||k<0) return 0;
    return (fact[m]*fiv[k]%mod)*fiv[m-k]%mod;
}
ll solve(ll n,ll m) {
    ll res=0;
    for(ll i=0;;++i) {
        if(n-i*m<i) break;
        res=(res+C(n-i*m,i))%mod;
    }
    return res;
}
ll f[maxn];
struct Matrix{
    ll a[maxn][maxn];
    void init() {
        memset(a, 0, sizeof(a));
    }
};
Matrix mul(Matrix a,Matrix b){
    Matrix ans;
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            ans.a[i][j] = 0;
            for(int k=0;k<maxn;++k){
                ans.a[i][j]=(ans.a[i][j]+(a.a[i][k]*b.a[k][j]%mod))%mod;
            }
        }
    } 
    return ans;
}
Matrix qpow(Matrix ans,ll n,ll m){
    Matrix p;
    p.init();
    p.a[0][0]=p.a[0][m-1]=1;
    for(int i=1;i<m;++i) p.a[i][i-1]=1;
    while(n) {
        if(n&1) ans=mul(p,ans);
        p=mul(p,p);
        n>>=1;
    } 
    return ans;
}

int main() {
    init();
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<m;++i) {
        f[i]=solve(i,m-1);
    }
    if(n<m) printf("%lld\n",f[n]);
    else {
        Matrix res;
        res.init();
        for(int i=0;i<m;++i) res.a[i][0]=f[m-i-1];
        // for(int i=0;i<m;++i) {
        //     for(int j=0;j<m;++j) {
        //         cout<<p.a[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        res=qpow(res,n-m+1,m);
        printf("%lld\n",res.a[0][0]);
    }
    return 0;
}