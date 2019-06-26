#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
typedef double db;
typedef vector<int> vi;
const int maxn=505;
double x[maxn],y[maxn];
int f[maxn],s[maxn];
double px[maxn][2],py[maxn][2];
double tpx[maxn][2],tpy[maxn][2];
vi v[maxn][2];
int n;
db alpha=0.001;

db dis(db x1,db y1,db x2,db y2) {
    return sqr(x1-x2)+sqr(y1-y2);
}
db solve() {
    db ans=0.0;
    rep(i,1,n) {
        ans+=dis(x[i],y[i],px[f[i]][0],py[f[i]][0]);
        ans+=dis(px[f[i]][0],py[f[i]][0],px[s[i]][1],py[s[i]][1]);
    }
    return ans;
}
void run() {
    rep(i,1,n) {
        tpx[i][0]=px[i][0];
        tpx[i][1]=px[i][1];
        tpy[i][0]=py[i][0];
        tpy[i][1]=py[i][1];
    }
    // 0
    rep(i,1,n) {
        for(auto u:v[i][0]) {
            px[i][0]-=alpha*2.0*(tpx[i][0]*2.0-x[u]-tpx[s[u]][1]);
            py[i][0]-=alpha*2.0*(tpy[i][0]*2.0-y[u]-tpy[s[u]][1]);
        }
    }
    // 1
    rep(i,1,n) {
        for(auto u:v[i][1]) {
            px[i][1]-=alpha*2.0*(tpx[i][1]-tpx[u][0]);
            py[i][1]-=alpha*2.0*(tpy[i][1]-tpy[u][0]);
        }
    }
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lf%lf",&x[i],&y[i]);
    rep(i,1,n) {
        scanf("%d",&f[i]);
        v[f[i]][0].pb(i);
    }
    rep(i,1,n) {
        scanf("%d",&s[i]);
        v[s[i]][1].pb(f[i]);
    }
    mem(px,0);
    mem(py,0);
    int cnt=10000;
    rep(i,1,cnt) run();
    printf("%.10lf\n",solve());
    return 0;
}