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

const int maxn=5050;
int seg[maxn];
int n,q;
struct Node {
    int l,r;
    bool operator<(const Node& e) const {
        if(l==e.l) return r<e.r;
        return l<e.l;
    }
} node[maxn];
int p[maxn*4][3];

void add(int x,int id,int val) {
    for(int i=x;i<=n;i+=lowbit(i)) {
        p[i][id]+=val;
    }
}
int calc(int x,int id) {
    if(x==0) return 0;
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i)) {
        res+=p[i][id];
    }
    return res;
}
int qry(int l,int r,int id) {
    if(l>r) return 0;
    return calc(r,id)-calc(l-1,id);
}

int main() {
    scanf("%d%d",&n,&q);
    mem(seg,0);
    rep(i,1,q) {
        scanf("%d%d",&node[i].l,&node[i].r);
        rep(j,node[i].l,node[i].r) {
            seg[j]++;
        }
    }
    int sum=0;
    rep(i,1,n) if(seg[i]) sum++;
    rep(i,1,2) {
        rep(j,1,n) {
            if(seg[j]==i) {
                add(j,i,1);
            }
        }
    }
    int ans=0;
    sort(node+1,node+1+q);
    rep(i,1,q) {
        rep(j,i+1,q) {
            if(node[j].l<=node[i].r) {
                if(node[j].r<=node[i].r) {
                    int res=qry(node[i].l,node[j].l-1,1)+qry(node[j].l,node[j].r,2)+qry(node[j].r+1,node[i].r,1);
                    if(sum-res>ans) ans=sum-res;
                }
                else {
                    int res=qry(node[i].l,node[j].l-1,1)+qry(node[j].l,node[i].r,2)+qry(node[i].r+1,node[j].r,1);
                    if(sum-res>ans) ans=sum-res;
                }
            }
            else {
                int res=qry(node[i].l,node[i].r,1)+qry(node[j].l,node[j].r,1);
                if(sum-res>ans) ans=sum-res;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}