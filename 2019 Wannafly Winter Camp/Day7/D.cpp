#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const ll mod=998244353ll;
const int maxn=25;
int n;

// void dfs(int depth,int cnt,int pre,int l,int r) {
//     if(2*n-depth<abs(l-r)) return;
//     if(depth==2*n) {
//         // if(l==r) cout<<s<<endl;
//         if(l==r) ans=(ans+1)%mod;
//         return;
//     }
//     if(cnt==0) {
//         dfs(depth+2,cnt+2,0,l,r);
//     }
//     if(pre!=2&&l>=1) dfs(depth+1,0,1,l-1,r);
//     if(pre!=1&&r>=1) dfs(depth+1,0,2,l,r-1);
// }

ll ans[20]={1,2,6,14,38,100,268,726,1974,5404,14852,40972,113388,314632,875112,2439014,6810102,19045612,53341428,149589348};

int main() {
    scanf("%d",&n);
    printf("%lld\n",ans[n-1]);
    return 0;
}