#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+5;
vector<int> e[maxn];
int p[maxn];
int a[maxn];
int depth[maxn];
int fa[maxn][21];
pii seg[maxn*4];
int n;
void dfs(int u,int pre) {
    depth[u]=depth[pre]+1;
    fa[u][0]=pre;
    rep(i,1,20) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto v:e[u]) {
        if(v==pre) continue;
        dfs(v,u);
    }
}
int LCA(int x,int y) {
    if(depth[x]<depth[y]) swap(x,y);
    per(i,20,0) {
        if(depth[fa[x][i]]>=depth[y]) {
            x=fa[x][i];
        }
    }
    if(x==y) return x;
    per(i,20,0) {
        if(fa[x][i]!=fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
int dis(int x,int y) {
    int lca=LCA(x,y);
    return depth[x]+depth[y]-depth[lca]*2;
}
pii merge(pii x,int y) {
    if(x.fi<0) return mp(-1,-1);
    int o1=dis(x.fi,x.se);
    int o2=dis(x.fi,y);
    int o3=dis(x.se,y);
    if(o1+o2==o3) return mp(x.se,y);
    if(o1+o3==o2) return mp(x.fi,y);
    if(o2+o3==o1) return x;
    return mp(-1,-1);
}
pii merge(pii x,pii y) {
    if(x.fi<0||y.fi<0) return mp(-1,-1);
    x=merge(x,y.fi);
    if(x.fi<0) return x;
    x=merge(x,y.se);
    return x;
}
void upd(int root) {
    seg[root]=merge(seg[root<<1],seg[root<<1|1]);
}
void build(int root,int l,int r) {
    if(l==r) {
        seg[root]=mp(a[l],a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    upd(root);
    // cout<<l<<" "<<r<<" "<<seg[root].fi<<" "<<seg[root].se<<"\n";
}
void update(int root,int l,int r,int index) {
    if(l>index||r<index) return;
    if(l==r) {
        seg[root]=mp(a[l],a[l]);
        return;
    }
    int mid=(l+r)>>1;
    update(root<<1,l,mid,index);
    update(root<<1|1,mid+1,r,index);
    upd(root);
}
int solve(int root,int l,int r,pii &prev) {
    if(seg[root].fi>=0) {
        if(prev.fi<0) {
            prev=seg[root];
            return r+1;
        }
        pii temp=merge(seg[root],prev);
        if(temp.fi>=0) {
            prev=temp;
            return r+1;
        }
    }
    if(l==r) return l;
    int mid=(l+r)>>1;
    int p=solve(root<<1,l,mid,prev);
    if(p<=mid) return p;
    return solve(root<<1|1,mid+1,r,prev);
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&p[i]);
    rep(i,2,n) {
        int u;
        scanf("%d",&u);
        e[u].pb(i);
        e[i].pb(u);
    }
    rep(i,1,n) a[p[i]]=i;
    dfs(1,0);
    build(1,0,n-1);
    int q;
    scanf("%d",&q);
    while(q--) {
        int o;
        scanf("%d",&o);
        if(o==1) {
            int u,v;
            scanf("%d%d",&u,&v);
            swap(p[u],p[v]);
            a[p[u]]=u;
            a[p[v]]=v;
            update(1,0,n-1,p[u]);
            update(1,0,n-1,p[v]);
        }
        else {
            pii p=mp(-1,-1);
            printf("%d\n",solve(1,0,n-1,p));
        }
    }
    return 0;
}