#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<cmath>
#include<unordered_map>

using namespace std;
namespace FastIO {
	#define BUF_SIZE 20000000
	bool IOError = 0;
	inline char NextChar() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOError = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool Blank(char c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t';
	}

	template<class T> inline void Read(T &x) {
		char c;
		while(Blank(c = NextChar()));
		if(!IOError) {
			for(x = 0; '0' <= c && c <= '9'; c = NextChar())
				x = (x << 3) + (x << 1) + c - '0';
		}
	}
}

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
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n,q;
vector<int> e[maxn];
int fa[maxn][17];
int depth[maxn];
int max_dep;
int dp[maxn][21];
int in[maxn];
int dfs_clock;
int seg[maxn*4];
int seg2[maxn*4];

void build(int root,int l,int r) {
    if(l==r) {
        seg[root]=in[l];
        seg2[root]=in[l];
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    seg[root]=min(seg[root<<1],seg[root<<1|1]);
    seg2[root]=max(seg2[root<<1],seg2[root<<1|1]);
}
int qry(int root,int l,int r,int ql,int qr) {
    if(l>qr||r<ql) return inf;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(l>=ql&&r<=qr) {
        if(seg[root<<1]<seg[root<<1|1])
            return qry(root<<1,l,mid,ql,qr);
        else
            return qry(root<<1|1,mid+1,r,ql,qr);
    }
    int p=qry(root<<1,l,mid,ql,qr);
    int q=qry(root<<1|1,mid+1,r,ql,qr);
    if(p==inf) return q;
    else if(q==inf) return p;
    else {
        if(in[p]<in[q]) return p;
        else return q;
    }
}
int qry2(int root,int l,int r,int ql,int qr) {
    if(l>qr||r<ql) return inf;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(l>=ql&&r<=qr) {
        if(seg2[root<<1]>seg2[root<<1|1])
            return qry2(root<<1,l,mid,ql,qr);
        else
            return qry2(root<<1|1,mid+1,r,ql,qr);
    }
    int p=qry2(root<<1,l,mid,ql,qr);
    int q=qry2(root<<1|1,mid+1,r,ql,qr);
    if(p==inf) return q;
    else if(q==inf) return p;
    else {
        if(in[p]>in[q]) return p;
        else return q;
    }
}
void dfs(int u,int pre) {
    depth[u]=depth[pre]+1;
    fa[u][0]=pre;
    in[u]=++dfs_clock;
    rep(i,1,16) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto v:e[u]) {
        if(v==pre) continue;
        dfs(v,u);
    }
}
int LCA(int x,int y) {
    if(x==y) return x;
    if(depth[x]<depth[y]) swap(x,y);
    per(i,16,0) {
        if(depth[fa[x][i]]>=depth[y]) {
            x=fa[x][i];
        }
        if(depth[x]==depth[y]) break;
    }
    if(x==y) return x;
    per(i,16,0) {
        if(fa[x][i]!=fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

struct Node {
    int x;
    int dep;
    Node() {}
    Node(int _x,int _dep) {
        x=_x;
        dep=_dep;
    }
} ans;
void upd(Node node) {
    if(node.dep>ans.dep) {
        ans=node;
    }
}
int query(int l,int r) {
    if(l==r) return l;
    int rt=-1;
    per(i,17,0) {
        if(l+(1<<i)-1<=r) {
            if(rt==-1) rt=dp[l][i];
            else rt=LCA(rt,dp[l][i]);
            l=l+(1<<i);
        }
        if(l>r) break;
    }
    return rt;
}
void solve(int ql,int qr) {
    int p=qry(1,1,n,ql,qr);
    ans.dep=-1;
    Node node;
    if(p==ql) {
        int rt=query(ql+1,qr);
        node=Node(p,depth[rt]);
        upd(node);
    }
    else if(p==qr) {
        int rt=query(ql,qr-1);
        node=Node(p,depth[rt]);
        upd(node);
    }
    else {
        int rt=query(ql,p-1);
        int rt2=query(p+1,qr);
        rt=LCA(rt,rt2);
        node=Node(p,depth[rt]);
        upd(node);
    }
    p=qry2(1,1,n,ql,qr);
    if(p==ql) {
        int rt=query(ql+1,qr);
        node=Node(p,depth[rt]);
        upd(node);
    }
    else if(p==qr) {
        int rt=query(ql,qr-1);
        node=Node(p,depth[rt]);
        upd(node);
    }
    else {
        int rt=query(ql,p-1);
        int rt2=query(p+1,qr);
        rt=LCA(rt,rt2);
        node=Node(p,depth[rt]);
        upd(node);
    }
}
void out(int x) {
    if(x>=10) out(x/10);
    putchar((x%10+'0'));
}

int main() {
    // scanf("%d%d",&n,&q);
    // gen();return 0;
    FastIO::Read(n);
    FastIO::Read(q);
    rep(i,2,n) {
        int p;
        // scanf("%d",&p);
        FastIO::Read(p);
        e[i].pb(p);
        e[p].pb(i);
    }
    depth[0]=-1;
    dfs_clock=0;
    dfs(1,0);
    rep(i,1,n) dp[i][0]=i;
    rep(j,1,17) {
        rep(i,1,n) {
            int idx=i+(1<<(j-1));
            if(idx>n) idx=n;
            dp[i][j]=LCA(dp[i][j-1],dp[idx][j-1]);
        }
    }
    build(1,1,n);
    while(q--) {
        int ql,qr;
        // scanf("%d%d",&ql,&qr);
        FastIO::Read(ql);
        FastIO::Read(qr);
        solve(ql,qr);
        // printf("%d %d\n",ans.x,ans.dep);
        out(ans.x);
        putchar(' ');
        out(ans.dep);
        putchar('\n');
    }
    return 0;
}