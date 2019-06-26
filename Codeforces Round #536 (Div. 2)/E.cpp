#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pr(x) cout<<x<<"\n";
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);

const int maxn=1e5+5;
int n,m,k;
struct Node {
    int s,t,d,w;
    bool operator<(const Node &e) const {
        if(w==e.w) return d<e.d;
        return w<e.w;
    }
    void input() { scanf("%d%d%d%d",&s,&t,&d,&w); }
} node[maxn];
ll dp[maxn][205];
int seg[maxn*4][2];
int d[maxn];
int w[maxn];

void build(int root,int l,int r) {
    if(l==r) {
        seg[root][0]=seg[root][1]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
}
void pushDown(int root) {
    if(seg[root<<1][1]<seg[root][1]) {
        seg[root<<1][1]=seg[root][1];
        seg[root<<1][0]=seg[root][0];
    }
    else if(seg[root<<1][1]==seg[root][1]) {
        seg[root<<1][0]=max(seg[root<<1][0],seg[root][0]);
    }
    if(seg[root<<1|1][1]<seg[root][1]) {
        seg[root<<1|1][1]=seg[root][1];
        seg[root<<1|1][0]=seg[root][0];
    }
    else if(seg[root<<1|1][1]==seg[root][1]) {
        seg[root<<1|1][0]=max(seg[root<<1|1][0],seg[root][0]);
    }
}
void update(int root,int l,int r,int ql,int qr,int d,int w) {
    if(l>qr||r<ql) return;
    if(l>=ql&&r<=qr) {
        if(seg[root][1]<w) {
            seg[root][1]=w;
            seg[root][0]=d;
        }
        else if(seg[root][1]==w) {
            seg[root][0]=max(seg[root][0],d);
        }
        return;
    }
    pushDown(root);
    int mid=(l+r)>>1;
    update(root<<1,l,mid,ql,qr,d,w);
    update(root<<1|1,mid+1,r,ql,qr,d,w);
}
void gao(int root,int l,int r) {
    if(l==r) {
        d[l]=seg[root][0];
        w[l]=seg[root][1];
        return;
    }
    pushDown(root);
    int mid=(l+r)>>1;
    gao(root<<1,l,mid);
    gao(root<<1|1,mid+1,r);
}

ll dfs(int i,int j) {
    if(i>n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll res;
    if(j!=0) {
        if(d[i]==0) res=dfs(i+1,j);
        else res=min(dfs(d[i]+1,j)+w[i],dfs(i+1,j-1));
    }
    else {
        if(d[i]==0) res=dfs(i+1,j);
        else res=dfs(d[i]+1,j)+w[i];
    }
    return dp[i][j]=res;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,k) node[i].input();
    sort(node+1,node+1+k);
    build(1,1,n);
    rep(i,1,k) {
        update(1,1,n,node[i].s,node[i].t,node[i].d,node[i].w);
    }
    gao(1,1,n);
    mem(dp,-1);
    // rep(i,1,n) printf("%d %d %d\n",i,d[i],w[i]);
    ll ans=dfs(1,m);
    // printf("%lld\n",dp[1][0]);
    printf("%lld\n",ans);
    return 0;
}