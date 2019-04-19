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
const ll mod=1e9+7;
const int maxn=105;
int n;
ll k;
int p[maxn];
struct matrix {
    ll a[maxn][maxn];
    void clear() {
        mem(a,0);
    }
};
matrix mul(matrix x,matrix y) {
    matrix z;
    z.clear();
    rep(i,0,maxn-1) {
        rep(j,0,maxn-1) {
            rep(t,0,maxn-1) {
                z.a[i][j]=(x.a[i][t]*y.a[t][j]%mod+z.a[i][j])%mod;
            }
        }
    }
    return z;
}
int solve(int x) {
    if(x==0) return 0;
    return x*(x-1)/2;
}
ll qpow(ll a,ll n) {
    ll res=1;
    ll p=a%mod;
    while(n) {
        if(n&1) res=res*p%mod;
        p=p*p%mod;
        n>>=1;
    }
    return res;
}

int main() {
    scanf("%d%lld",&n,&k);
    int cur=0;
    rep(i,1,n) {
        scanf("%d",&p[i]);
        if(!p[i]) cur++;
    }
    int x=0;
    rep(i,1,cur) {
        if(!p[i]) x++;
    }
    matrix ans;
    ans.clear();
    ans.a[x][0]=1;
    matrix tr;
    tr.clear();
    rep(j,0,cur) {
        if(cur-j>=0&&n-2*cur+j>=0) {
            tr.a[j][j]=solve(cur)+solve(n-cur)+j*(cur-j)+(cur-j)*(n-2*cur+j);
        }
        if(j-1>=0&&n-2*cur+j-1>=0) tr.a[j][j-1]=(cur-j+1)*(cur-j+1);
        if(j+1<=cur&&n-2*cur+j+1>=0) tr.a[j][j+1]=(j+1)*(n-2*cur+j+1);
    }
    while(k) {
        if(k&1) ans=mul(tr,ans);
        tr=mul(tr,tr);
        k>>=1;
    }
    ll res=ans.a[cur][0];
    ll q=0;
    rep(i,0,cur) q=(q+ans.a[i][0])%mod;
    res=res*qpow(q,mod-2)%mod;
    printf("%lld\n",res);
    return 0;
}