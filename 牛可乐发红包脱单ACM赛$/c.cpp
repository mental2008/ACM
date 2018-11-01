#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>

using namespace std;

namespace FastIO {
	#define BUF_SIZE 10000000
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
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n;
int a[maxn];
ll ans;
int Min[maxn*4];
int Max[maxn*4];
void build(int root,int l,int r) {
    if(l==r) {
        Min[root]=Max[root]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    Min[root]=min(Min[root<<1],Min[root<<1|1]);
    Max[root]=max(Max[root<<1],Max[root<<1|1]);
}

int qlmax(int root,int l,int r,int ql,int qr,int val) {
    if(l>qr||r<ql) return 0;
    if(Max[root]<val) return 0;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(l>=ql&&r<=qr) {
        if(Max[root<<1|1]>=val)
            return qlmax(root<<1|1,mid+1,r,ql,qr,val);
        else
            return qlmax(root<<1,l,mid,ql,qr,val);
    }
    int p=qlmax(root<<1|1,mid+1,r,ql,qr,val);
    if(p!=0) return p;
    return qlmax(root<<1,l,mid,ql,qr,val);
}
int qrmax(int root,int l,int r,int ql,int qr,int val) {
    if(l>qr||r<ql) return n+1;
    if(Max[root]<=val) return n+1;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(l>=ql&&r<=qr) {
        if(Max[root<<1]>val)
            return qrmax(root<<1,l,mid,ql,qr,val);
        else
            return qrmax(root<<1|1,mid+1,r,ql,qr,val);
    }
    int p=qrmax(root<<1,l,mid,ql,qr,val);
    if(p!=n+1) return p;
    return qrmax(root<<1|1,mid+1,r,ql,qr,val);
}

int qlmin(int root,int l,int r,int ql,int qr,int val) {
    if(l>qr||r<ql) return 0;
    if(Min[root]>val) return 0;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(l>=ql&&r<=qr) {
        if(Min[root<<1|1]<=val)
            return qlmin(root<<1|1,mid+1,r,ql,qr,val);
        else
            return qlmin(root<<1,l,mid,ql,qr,val);
    }
    int p=qlmin(root<<1|1,mid+1,r,ql,qr,val);
    if(p!=0) return p;
    return qlmin(root<<1,l,mid,ql,qr,val);
}
int qrmin(int root,int l,int r,int ql,int qr,int val) {
    if(l>qr||r<ql) return n+1;
    if(Min[root]>=val) return n+1;
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(l>=ql&&r<=qr) {
        if(Min[root<<1]<val)
            return qrmin(root<<1,l,mid,ql,qr,val);
        else
            return qrmin(root<<1|1,mid+1,r,ql,qr,val);
    }
    int p=qrmin(root<<1,l,mid,ql,qr,val);
    if(p!=n+1) return p;
    return qrmin(root<<1|1,mid+1,r,ql,qr,val);
}

ll calc(int x) {
    if(x<=1) return 0;
    return 1ll*x*(x-1)/2;
}

int main() {
    int caseCnt;
    // scanf("%d",&caseCnt);
    FastIO::Read(caseCnt);
    while(caseCnt--) {
        // scanf("%d",&n);
        // rep(i,1,n) scanf("%d",&a[i]);
        FastIO::Read(n);
        rep(i,1,n) FastIO::Read(a[i]);
        ans=0;
        build(1,1,n);
        rep(i,1,n) {
            // cout<<"i = "<<i<<endl;
            int l=qlmax(1,1,n,1,i-1,a[i]);
            int r=qrmax(1,1,n,i+1,n,a[i]);
            l++;r--;
            // cout<<l<<" "<<r<<endl;
            ans+=1ll*a[i]*(calc(r-l+1)-calc(i-l)-calc(r-i));
            l=qlmin(1,1,n,1,i-1,a[i]);
            r=qrmin(1,1,n,i+1,n,a[i]);
            l++;r--;
            // cout<<l<<" "<<r<<endl;
            ans+=1ll*(-a[i])*(calc(r-l+1)-calc(i-l)-calc(r-i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}