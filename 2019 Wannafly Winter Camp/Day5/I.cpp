#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=2e5+5;
int n,q;
ll x;
ll a[maxn];
ll seg[maxn*4];
ll mark[maxn*4];
ll pre[maxn];
ll pre2[maxn];
int cnt;
int cnt2;

void build(int root,int l,int r) {
    mark[root]=-1;
    if(l==r) {
        seg[root]=(a[l]<=x)?1:0;
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    seg[root]=seg[root<<1]+seg[root<<1|1];
}
void pushDown(int root,int l,int r) {
    if(mark[root]!=-1) {
        mark[root<<1]=mark[root];
        mark[root<<1|1]=mark[root];
        int mid=(l+r)>>1;
        seg[root<<1]=(mid-l+1)*mark[root];
        seg[root<<1|1]=(r-mid)*mark[root];
        mark[root]=-1;
    }
}
void upd(int root,int l,int r,int ql,int qr,ll val) {
    if(ql>qr) return;
    if(l>qr||r<ql) return;
    if(l>=ql&&r<=qr) {
        seg[root]=(r-l+1)*val;
        mark[root]=val;
        // printf("%d %d %lld %lld %lld\n",l,r,val,seg[root],mark[root]);
        return;
    }
    pushDown(root,l,r);
    int mid=(l+r)>>1;
    upd(root<<1,l,mid,ql,qr,val);
    upd(root<<1|1,mid+1,r,ql,qr,val);
    seg[root]=seg[root<<1]+seg[root<<1|1];
}
int qry(int root,int l,int r,int ql,int qr) {
    if(ql>qr) return 0;
    if(l>qr||r<ql) return 0;
    if(l>=ql&&r<=qr) return seg[root];
    pushDown(root,l,r);
    int mid=(l+r)>>1;
    return qry(root<<1,l,mid,ql,qr)+qry(root<<1|1,mid+1,r,ql,qr);
}
int main() {
    scanf("%d%d%lld",&n,&q,&x);
    rep(i,1,n) scanf("%lld",&a[i]);
    build(1,1,n);
    cnt=cnt2=0;
    pre[0]=pre2[0]=0;
    rep(i,1,n) {
        if(a[i]<=x) {
            cnt++;
            pre[cnt]=pre[cnt-1]+a[i];
        }
        else {
            cnt2++;
            pre2[cnt2]=pre2[cnt2-1]+a[i];
        }
    }
    // printf("%d %d\n",pre2[1],pre2[2]);
    while(q--) {
        int o;
        scanf("%d",&o);
        if(o==1) {
            int l,r;
            scanf("%d%d",&l,&r);
            // printf("o = 1, l = %d, r = %d\n",l,r);
            // printf("%d\n",qry(1,1,n,4,4));
            int p=qry(1,1,n,1,r);
            int p2=qry(1,1,n,1,l-1);
            ll ans=pre[p]-pre[p2];
            // printf("%d %d\n",p2,p);
            p=r-p;
            p2=l-1-p2;
            p2=max(0,p2);
            ans+=pre2[p]-pre2[p2];
            printf("%lld\n",ans);
        }
        else if(o==2) {
            int l,r;
            scanf("%d%d",&l,&r);
            int res=qry(1,1,n,l,r);
            // printf("o = 2, res = %d\n",res);
            // printf("%d\n",qry(1,1,n,1,3));
            upd(1,1,n,l,l+res-1,1);
            // printf("%d\n",qry(1,1,n,1,3));
            upd(1,1,n,l+res,r,0);
            // printf("%d\n",qry(1,1,n,4,4));
            // printf("%d %d\n",l+res,r);
        }
        else {
            int l,r;
            scanf("%d%d",&l,&r);
            int res=qry(1,1,n,l,r);
            res=(r-l+1)-res;
            upd(1,1,n,l,l+res-1,0);
            upd(1,1,n,l+res,r,1);
        }
    }
    return 0;
}