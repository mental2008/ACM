#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=1005;
int n,m;
ll a[maxn][maxn];
struct Node {
    int x,y;
    ll val;
    bool operator<(const Node& e) const {
        return val<e.val;
    }
} node[maxn];
int rkx[maxn][maxn];
int rky[maxn][maxn];
ll cntx[maxn];
ll cnty[maxn];
ll ans[maxn][maxn];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%lld",&a[i][j]);
    rep(i,1,n) {
        rep(j,1,m) {
            node[j].val=a[i][j];
            node[j].x=i;
            node[j].y=j;
        }
        sort(node+1,node+1+m);
        int cnt=0;
        rep(j,1,m) {
            if(node[j].val>node[j-1].val) cnt++;
            rkx[node[j].x][node[j].y]=cnt;
        }
        cntx[i]=cnt;
    }
    rep(j,1,m) {
        rep(i,1,n) {
            node[i].val=a[i][j];
            node[i].x=i;
            node[i].y=j;
        }
        sort(node+1,node+1+n);
        int cnt=0;
        rep(i,1,n) {
            if(node[i].val>node[i-1].val) cnt++;
            rky[node[i].x][node[i].y]=cnt;
        }
        cnty[j]=cnt;
    }
    rep(i,1,n) {
        rep(j,1,m) {
            if(rkx[i][j]<=rky[i][j]) {
                ans[i][j]=max(cnty[j],cntx[i]+rky[i][j]-rkx[i][j]);
            }
            else {
                ans[i][j]=max(cnty[j]+rkx[i][j]-rky[i][j],cntx[i]);
            }
        }
    }
    rep(i,1,n) {
        rep(j,1,m) printf("%lld ",ans[i][j]);
        puts("");
    }
    return 0;
}