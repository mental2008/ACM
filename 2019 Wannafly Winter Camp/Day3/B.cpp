#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define sqr(x) (x*x)
typedef long long ll;
typedef double db;

const db pi=acos(-1.0);
const db exps=1e-6;

struct point {
    db x,y;
    point() {}
    point(db a, db b) {
        x=a;
        y=b;
    }
    point operator + (const point b) const {
        return point( x + b.x, y + b.y);
    }
    point operator - (const point b) const {
        return point( x - b.x, y - b.y);
    }
    db len() {
        return sqrt( x * x + y * y );
    }
    void input() {
        scanf("%lf%lf",&x,&y);
    }
};
int dcmp(db x) {
    return (x > exps) - (x < -exps);
}
db cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
db dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
db dis(point a, point b) {
    return sqrt( dot(a - b, a - b) );
}
db angle(point a, point b) {
    db k = dot(a, b) / a.len() / b.len();
    k = max(k, -1.0); k = min(k, 1.0);
    return acos(k);
}
db ptoseg(point p, point a, point b) {
    if( dcmp( dot(p - a, b - a) ) <= 0 ) return dis(p, a);
    if( dcmp( dot(p - b, a - b) ) <= 0 ) return dis(p, b);
    return fabs(cross(p - a, b - a)) / dis(a, b);
}
point a, b;
point o;
db r;

db solve(db alpha) {
    point p(r*cos(alpha), r*sin(alpha));
    return dis(a, p) + dis(b, p);
}

db gao(point p) {
    point xx(1,0);
    db res=angle(p, xx);
    if(p.y<0) res=2*pi-res;
    return res;
}

int main() {
    // gen();
    // return 0;
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        a.input();
        b.input();
        o.input();
        a.x-=o.x; a.y-=o.y;
        b.x-=o.x; b.y-=o.y;
        o.x-=o.x; o.y-=o.y;
        scanf("%lf",&r);
        if(ptoseg(o, a, b) >= r) {
            db ll=gao(a);
            db rr=gao(b);
            if(ll>rr) swap(ll,rr);
            if(fabs(rr-ll)>pi) ll+=2*pi;
            if(ll>rr) swap(ll,rr);
            rep(i,1,50) {
                db temp=(rr-ll)/3.0;
                db ql=ll+temp;
                db qr=rr-temp;
                db ansl=solve(ql);
                db ansr=solve(qr);
                if(ansl<ansr) {
                    rr=qr;
                }
                else {
                    ll=ql;
                }
            }
            printf("%.3lf\n",solve(ll));
        }
        else {
            db alpha=angle(a, b);
            db disa=dis(a, o);
            db disb=dis(b, o);
            alpha-=acos(r/disa);
            alpha-=acos(r/disb);
            db ans=sqrt(sqr(disa)-sqr(r))+sqrt(sqr(disb)-sqr(r))+alpha*r;
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}