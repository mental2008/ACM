#include <bits/stdc++.h>

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
typedef vector<int> vi;
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n,k;
ll A,B;
ll a[maxn];
ll dp[50][maxn];

ll solve(int l,int r,int base,int lt,int rt) {
    int cnt=rt-lt+1;
    // if(dp[base][cnt]!=-1) return dp[base][cnt];
    if(cnt==0) return A;
    int mid=(l+r)>>1;
    ll res=1ll*B*cnt*(r-l+1);
    if(base==0) return res;
    int i=lt;
    for(;i<=rt;++i) {
        if(a[i]>mid) break;
    }
    res=min(res,solve(l,mid,base-1,lt,i-1)+solve(mid+1,r,base-1,i,rt));
    return res;
    // printf("%d %d %d %d %lld\n",l,r,base,cnt,res);
    // return dp[base][cnt]=res;
}

int main() {
    while(~scanf("%d%d%lld%lld",&n,&k,&A,&B)) {
        rep(i,1,k) scanf("%lld",&a[i]);
        sort(a+1,a+1+k);
        // mem(dp,-1);
        ll ans=solve(1,(1<<n),n,1,k);
        printf("%lld\n",ans);
    }
    return 0;
}