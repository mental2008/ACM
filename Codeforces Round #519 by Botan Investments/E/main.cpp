#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=3e5+5;
int n,m;
struct Node {
    ll id;
    ll p,q;
} e[maxn];
ll pre[maxn];
ll lst[maxn];
ll ans[maxn];
ll a[maxn],b[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        e[i].id=i;
        e[i].p=x+y;
        e[i].q=x-y;
        a[i]=x+y;
        b[i]=x-y;
    }
    auto cmp=[=](Node a,Node b) {
        return a.q<b.q;
    };
    sort(e+1,e+1+n,cmp);
    pre[0]=0;
    rep(i,1,n) pre[i]=pre[i-1]+e[i].q;
    lst[n+1]=0;
    per(i,n,1) lst[i]=lst[i+1]+e[i].q;
    ll sum=0;
    rep(i,1,n) sum+=e[i].p;
    rep(i,1,n) {
        int id=e[i].id;
        ans[id]=0;
        ans[id]+=(sum-e[i].p);
        ans[id]+=(e[i].p*(n-1));
        ans[id]+=pre[i-1];
        ans[id]-=(e[i].q*(i-1));
        ans[id]+=(e[i].q*(n-i));
        ans[id]-=lst[i+1];
        ans[id]>>=1;
    }
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        ll temp=min(a[u]+b[u]+a[v]-b[v],a[v]+b[v]+a[u]-b[u]);
        temp>>=1;
        ans[u]-=temp;
        ans[v]-=temp;
    }
    rep(i,1,n) {
        printf("%lld%c",ans[i],(i==n?'\n':' '));
    }
    return 0;
}
