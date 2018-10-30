#include <bits/stdc++.h>
using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF=0x3f3f3f3f;
const double exps=1e-8;
const double pi=acos(-1.0);
const int maxn=1005;
int cmp(ll x) {
    if(x==0) return 0;
    else if(x>0) return 1;
    return -1;
}
struct point {
    ll x,y;
    point() {}
    point(ll a,ll b): x(a),y(b) {}
    friend point operator+(const point &a,const point &b) {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator-(const point &a,const point &b) {
        return point(a.x-b.x,a.y-b.y);
    }
    friend point operator*(const point &a,const ll &b) {
        return point(a.x*b,a.y*b);
    }
    friend point operator*(const ll &a,const point &b) {
        return point(a*b.x,a*b.y);
    }
    friend point operator/(const point &a,const ll &b) {
        return point(a.x/b,a.y/b);
    }
    friend bool operator==(const point &a,const point &b) {
        return a.x==b.x&&a.y==b.y;
    }
    bool operator<(const point &e) const {
        if(x==e.x) return y<e.y;
        return x<e.x;
    }
    bool operator==(const point &e) const {
        return x==e.x&&y==e.y;
    }
    bool operator!=(const point &e) const {
        return x!=e.x||y!=e.y;
    }
};
ll det(const point &a,const point &b) {
    return a.x*b.y-a.y*b.x;
}
ll dot(const point &a,const point &b) {
    return a.x*b.x+a.y*b.y;
}
struct line {
    point a,b;
    line() {}
    line(point x,point y): a(x),b(y) {}
} seg[maxn];
bool PointOnSegment(point p,point s,point t) {
    return cmp(det(p-s,t-s))==0&&cmp(dot(p-s,p-t))<=0;
}
bool parallel(line a,line b) {
    return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(line a,line b,point &res) {
    if(parallel(a,b)) return false;
    ll s1=det(a.a-b.a,b.b-b.a);
    ll s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a);
    if(res.x%(s1-s2)==0&&res.y%(s1-s2)==0) {
        res=res/(s1-s2);
        return true;
    }
    return false;
}
int n;
set<point> st;
vector<point> vec;
ll gcd(ll a,ll b) {
    return (b==0?a:gcd(b,a%b));
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%lld%lld%lld%lld",&seg[i].a.x,&seg[i].a.y,&seg[i].b.x,&seg[i].b.y);
    }
    st.clear();
    ll ans=0;
    rep(i,1,n) {
        vec.clear();
        rep(j,i+1,n) {
            point res;
            if(line_make_point(seg[i],seg[j],res)) {
                if(abs(res.x)>1000000||abs(res.y)>1000000) continue;
                if(PointOnSegment(res,seg[i].a,seg[i].b)&&PointOnSegment(res,seg[j].a,seg[j].b)) {
                    if(st.find(res)==st.end()) {
                        ans--;
                    }
                    vec.push_back(res);
                }
            }
        }
        int len=(int)vec.size();
        rep(j,0,len-1) st.insert(vec[j]);
    }
    rep(i,1,n) {
        ll res=gcd(abs(seg[i].a.x-seg[i].b.x),abs(seg[i].a.y-seg[i].b.y))+1;
        ans+=res;
    }
    printf("%lld\n",ans);
    return 0;
}
