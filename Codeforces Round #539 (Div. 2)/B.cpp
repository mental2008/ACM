#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int inf=0x3f3f3f3f;
const int maxn=5e4+5;;
int a[maxn];
int n;

int main() {
    scanf("%d",&n);
    int Min=inf;
    rep(i,1,n) {
        scanf("%d",&a[i]);
        Min=min(Min,a[i]);
    }
    int ans=inf;
    rep(i,1,100) {
        int p=-1;
        int res=0;
        rep(j,1,n) {
            if(a[j]%i==0&&(p==-1||a[j]>a[p])) {
                p=j;
            }
            res+=a[j];
        }
        if(p!=-1) {
            ans=min(ans,res+Min*i+a[p]/i-a[p]-Min);
        }
    }
    printf("%d\n",ans);
    return 0;
}