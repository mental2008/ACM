#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=105;
int n,k;
int vis[maxn];

int main() {
    scanf("%d%d",&n,&k);
    mem(vis,0);
    rep(i,1,n) {
        int val;
        scanf("%d",&val);
        vis[val]++;
        k=max(k,vis[val]);
    }
    int ans=0;
    rep(i,1,100) {
        if(vis[i]) {
            ans+=k-vis[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}