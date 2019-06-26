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

const int maxn=505;
ll a[maxn][maxn];
ll b[maxn][maxn];
vector<ll> va[maxn*2];
vector<ll> vb[maxn*2];
int n,m;

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%lld",&a[i][j]);
    rep(i,1,n) rep(j,1,m) scanf("%lld",&b[i][j]);
    rep(i,1,n) {
        rep(j,1,m) {
            va[i+j].pb(a[i][j]);
            vb[i+j].pb(b[i][j]);
        }
    }
    rep(i,2,n+m) {
        sort(va[i].begin(),va[i].end());
        sort(vb[i].begin(),vb[i].end());
        int len=va[i].size();
        rep(j,0,len-1) if(va[i][j]!=vb[i][j]) return 0*puts("NO");
    }
    puts("YES");
    return 0;
}