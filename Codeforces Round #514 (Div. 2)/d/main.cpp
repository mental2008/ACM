#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const double exps=1e-8;
const int maxn=1e5+5;
int n;
ll x[maxn];
ll y[maxn];
bool judge() {
    bool pos=1,neg=1;
    rep(i,1,n) {
        if(y[i]>0) neg=0;
        else pos=0;
    }
    if(pos||neg) return true;
    return false;
}
struct Segment {
    double l,r;
    bool operator<(const Segment& e) const {
        if(fabs(l-e.l)<exps) return r<e.r;
        return l<e.l;
    }
} seg[maxn];
bool check(double p) {
    rep(i,1,n) {
        if(fabs(p-(double)y[i])>p) return false;
        double temp=sqrt(p*p-fabs(p-(double)y[i])*fabs(p-(double)y[i]));
        seg[i].l=x[i]-temp;
        seg[i].r=x[i]+temp;
    }
    double tl=seg[1].l,tr=seg[1].r;
    rep(i,2,n) {
        if(seg[i].l-tr>exps||tl-seg[i].r>exps) return false;
        if(seg[i].l>tl) tl=seg[i].l;
        if(seg[i].r<tr) tr=seg[i].r;
    }
    return true;
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    if(judge()) {
        double L=0,R=1e15;
        double ans=1e15;
        rep(i,1,n) y[i]=abs(y[i]);
        while(fabs(R-L)>exps) {
            double mid=(L+R)/2;
            if(check(mid)) {
                ans=mid;
                R=mid;
            }
            else L=mid;
        }
        printf("%.10lf\n",ans);
    }
    else {
        puts("-1");
    }
    return 0;
}
