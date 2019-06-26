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
const int N=62;
const int maxn=4e5+5;
bool vis[305];
int n,q;
int a[maxn];
bitset<N> seg[maxn*4];
bitset<N> mark[maxn*4];
int sum[maxn*4];
int smark[maxn*4];
int prime[N];
int pre[N];
int cnt;

int qpow(int a,int n) {
    int res=1;
    int p=a;
    while(n) {
        if(n&1) res=1ll*res*p%mod;
        p=1ll*p*p%mod;
        n>>=1;
    }
    return res;
}
void build(int root,int l,int r) {
    mark[root].reset();
    smark[root]=1;
    if(l==r) {
        seg[root].reset();
        rep(i,0,cnt-1) {
            // cout<<a[l]<<" "<<prime[i]<<"\n";
            if(a[l]%prime[i]==0) {
                seg[root].set(i);
            }
        }
        // cout<<seg[root]<<"\n";
        sum[root]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    seg[root]=(seg[root<<1]|seg[root<<1|1]);
    sum[root]=1ll*sum[root<<1]*sum[root<<1|1]%mod;
}
void pushDown(int root,int l,int r) {
    if(smark[root]!=1) {
        seg[root<<1]|=mark[root];
        seg[root<<1|1]|=mark[root];
        mark[root<<1]|=mark[root];
        mark[root<<1|1]|=mark[root];
        mark[root].reset();
        int mid=(l+r)>>1;
        sum[root<<1]=1ll*sum[root<<1]*qpow(smark[root],mid-l+1)%mod;
        sum[root<<1|1]=1ll*sum[root<<1|1]*qpow(smark[root],r-mid)%mod;
        smark[root<<1]=1ll*smark[root<<1]*smark[root]%mod;
        smark[root<<1|1]=1ll*smark[root<<1|1]*smark[root]%mod;
        smark[root]=1;
    }
}
void update(int root,int l,int r,int ql,int qr,int x) {
    if(l>qr||r<ql) return;
    if(l>=ql&&r<=qr) {
        bitset<N> temp;
        temp.reset();
        rep(i,0,cnt-1) {
            if(x%prime[i]==0) {
                temp.set(i);
            }
        }
        seg[root]|=temp;
        mark[root]|=temp;
        sum[root]=1ll*sum[root]*qpow(x,r-l+1)%mod;
        smark[root]=1ll*smark[root]*x%mod;
        return;
    }
    pushDown(root,l,r);
    int mid=(l+r)>>1;
    update(root<<1,l,mid,ql,qr,x);
    update(root<<1|1,mid+1,r,ql,qr,x);
    seg[root]=(seg[root<<1]|seg[root<<1|1]);
    sum[root]=1ll*sum[root<<1]*sum[root<<1|1]%mod;
}
bitset<N> res;
int query(int root,int l,int r,int ql,int qr) {
    if(l>qr||r<ql) return 1;
    if(l>=ql&&r<=qr) {
        res|=seg[root];
        return sum[root];
    }
    pushDown(root,l,r);
    int mid=(l+r)>>1;
    int p=query(root<<1,l,mid,ql,qr);
    int q=query(root<<1|1,mid+1,r,ql,qr);
    return 1ll*p*q%mod;
}

int main() {
    cnt=0;
    for(int i=2;i<=300;++i) {
        if(!vis[i]) {
            int inv=qpow(i,mod-2);
            // cout<<i<<" "<<inv[cnt]<<"\n";
            pre[cnt]=1ll*inv*(i-1)%mod;
            prime[cnt++]=i;
            for(int j=i*2;j<=300;j+=i) {
                vis[j]=1;
            }
        }
    }
    scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    build(1,1,n);
    while(q--) {
        char o[5];
        scanf("%s",o);
        if(o[0]=='M') {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            update(1,1,n,l,r,x);
        }
        else {
            int l,r;
            scanf("%d%d",&l,&r);
            res.reset();
            int ans=query(1,1,n,l,r);
            // cout<<res<<" "<<ans<<"\n";
            rep(i,0,cnt-1) {
                if(res[i]) {
                    // cout<<i<<" "<<prime[i]<<" "<<inv[i]<<"\n";
                    ans=1ll*ans*pre[i]%mod;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}