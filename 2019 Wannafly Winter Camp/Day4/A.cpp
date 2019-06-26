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

const int maxn=1e5+5;
ll x1[maxn],y11[maxn];
ll x2[maxn],y2[maxn];
int n,m;
ll solve(ll x) {
    if(x<0) return -x;
    return x;
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        scanf("%lld%lld",&x1[i],&y11[i]);
        scanf("%lld%lld",&x2[i],&y2[i]);
    }
    ll ans=0;
    rep(i,2,n) {
        ll res1=solve(x1[i]-x1[i-1])+solve(y11[i]-y11[i-1])+solve(x2[i]-x2[i-1])+solve(y2[i]-y2[i-1]);
        ll res2=solve(x1[i]-x2[i-1])+solve(y11[i]-y2[i-1])+solve(x2[i]-x1[i-1])+solve(y2[i]-y11[i-1]);
        ans+=min(res1,res2);
        // printf("%lld %lld\n",res1,res2);
    }
    ans+=solve(x1[n]-x2[n])+solve(y11[n]-y2[n]);
    printf("%lld\n",ans);
    return 0;
}