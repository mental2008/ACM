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

const int maxn=1e4+5;
int a[maxn];
vector<int> v[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        rep(i,1,m) v[i].clear();
        rep(i,1,n) {
            scanf("%d",&a[i]);
            v[a[i]].pb(i);
        }
        int ans=0;
        rep(i,1,m) {
            int len=v[i].size();
            rep(j,0,len-1) {
                if((j+1)<=len/k&&v[i][j]<=n/2) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}