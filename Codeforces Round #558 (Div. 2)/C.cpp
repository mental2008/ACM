#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const db exps=1e-4;
const db pi=acos(-1.0);

const int maxn=1005;
int n;
ll x[maxn],y[maxn];
ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}
struct Line {
    ll a,b,c;
    Line() {}
    Line(ll a,ll b,ll c):a(a),b(b),c(c) {}
    bool operator<(const Line& e) const {
        if(a==e.a) {
            if(b==e.b) return c<e.c;
            return b<e.b;
        }
        return a<e.a;
    }
};
set<Line> st;
vector<Line> v;
map<pii,ll> mp;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld%lld",&x[i],&y[i]);
    rep(i,1,n) {
        rep(j,i+1,n) {
            ll a=x[j]-x[i];
            ll b=y[j]-y[i];
            ll c=y[i]*(x[j]-x[i])-x[i]*(y[j]-y[i]);
            ll g=gcd(a,gcd(b,c));
            a/=g; b/=g; c/=g;
            if(a<0) {
                a*=-1; b*=-1; c*=-1;
            }
            st.insert(Line(a,b,c));
        }
    }
    ll len=(ll)st.size();
    ll ans=(len)*(len-1)/2;
    mp.clear();
    for(auto l:st) {
        ll g=gcd(l.a,l.b);
        mp[make_pair(l.a/g,l.b/g)]++;
    }
    for(auto it:mp) {
        ll cnt=it.se;
        ans-=cnt*(cnt-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}