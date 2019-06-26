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
const db pi=acos(-1.0);
struct point {
    double x,y,z;
    point() {}
    point(double a, double b,double c) {
        x = a;
        y = b;
        z = c;
    }
    point operator -(const point &b)const {
        return point(x - b.x, y - b.y, z - b.z);
    }
    point operator +(const point &b)const {
        return point(x + b.x, y + b.y, z + b.z);
    }
    point operator *(const double &k)const {
        return point(x * k, y * k, z * k);
    }
    point operator /(const double &k)const {
        return point(x / k, y / k, z / k);
    }
    double operator *(const point &b)const {
        return x * b.x + y * b.y + z * b.z;
    }
};
double dist(point p1, point p2) {
    return sqrt((p1 - p2)*(p1 - p2));
}
struct sphere {
    double r;
    point centre;
};
double SphereInterVS(sphere a, sphere b) {
    double d = dist(a.centre, b.centre);
    if(d>fabs(a.r+b.r)) return 0;
    if(d<fabs(a.r-b.r)) {
        double r=min(a.r,b.r);
        return 4.0/3.0*pi*r*r*r;
    }
    double alpha = acos((a.r*a.r + d*d - b.r*b.r) / (2.0 * a.r*d));
    double belta = acos((b.r*b.r + d*d - a.r*a.r) / (2.0 * b.r*d));
    // cout << alpha << " " << belta << "\n";
    double h1 = a.r * (1 - cos(alpha));
    double h2 = b.r * (1 - cos(belta));
    double v = pi / 3.0 * (3.0 * a.r * h1 * h1 - h1 * h1 * h1 + 3 * b.r * h2 * h2 - h2 * h2 * h2);
    // cout << v << endl;
    return v; // niubi
}
const int maxn=105;
sphere sp[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    rep(T,1,caseCnt) {
        int n;
        scanf("%d",&n);
        rep(i,1,n+1) {
            double x,y,z,r;
            scanf("%lf%lf%lf%lf",&x,&y,&z,&r);
            point p(x,y,z);
            sp[i].r=r;
            sp[i].centre=p;
        }
        double sum=0.0;
        rep(i,1,n) {
            // sum+=4.0/3.0*pi*sp[i].r*sp[i].r*sp[i].r;
            sum+=SphereInterVS(sp[i],sp[n+1]);
        }
        printf("Case #%d: %.10lf\n",T,sum);
    }
    return 0;
}