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
int n,m;
int a[maxn][maxn];
int b[maxn][maxn];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
    rep(i,1,n) rep(j,1,m) scanf("%d",&b[i][j]);
    rep(i,1,n) {
        rep(j,1,m) {
            if(a[i][j]!=b[i][j]) {
                if(i+1<=n&&j+1<=m) {
                    a[i][j]^=1;
                    a[i+1][j]^=1;
                    a[i][j+1]^=1;
                    a[i+1][j+1]^=1;
                }
            }
        }
    }
    bool ok=true;
    rep(i,1,n) {
        rep(j,1,m) {
            if(a[i][j]!=b[i][j]) ok=false;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}