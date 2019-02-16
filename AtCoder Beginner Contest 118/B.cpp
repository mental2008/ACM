#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=35;
int n,m;
int vis[maxn];

int main() {
    while(~scanf("%d%d",&n,&m)) {
        mem(vis,0);
        rep(i,1,n) {
            int k;
            scanf("%d",&k);
            rep(j,1,k) {
                int a;
                scanf("%d",&a);
                vis[a]++;
            }
        }
        int res=0;
        rep(i,1,m) {
            if(vis[i]==n) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}