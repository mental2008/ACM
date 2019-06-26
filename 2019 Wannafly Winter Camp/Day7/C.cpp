#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int maxn=5e5+5;
const db exps=1e-14;
db x;
struct line {
    db k,b;
} p[maxn];
int n;

db solve(db val) {
    x=val;
    db MAX=-1e18;
    db MIN=1e18;
    rep(i,1,n) {
        MAX=max(MAX,p[i].k*x+p[i].b);
        MIN=min(MIN,p[i].k*x+p[i].b);
    }
    db res=MAX-MIN;
    return res;
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%Lf%Lf",&p[i].k,&p[i].b);
    db l=-2e6-5.0,r=2e6+5.0;
    db ans=1e18;
    rep(i,1,100) {
        db len=(r-l)/3.0;
        db ql=l+len;
        db qr=r-len;
        db res1=solve(ql);
        db res2=solve(qr);
        ans=min(ans,res1);
        ans=min(ans,res2);
        if(fabs(res1-res2)<exps) {
            l=ql;
            r=qr;
        }
        else if(res1<=res2) {
            r=qr;
        }
        else {
            l=ql;
        }
    }
    printf("%.15Lf\n",ans);
    return 0;
}