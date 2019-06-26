#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=105;
int a[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int ans=INF;
    rep(i,1,n) {
        int res=0;
        rep(j,1,n) {
            res+=a[j]*(abs(i-j)+abs(j-1)+abs(i-1))*2;
        }
        ans=min(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}