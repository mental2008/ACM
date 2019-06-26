#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

int n,v;

int main() {
    scanf("%d%d",&n,&v);
    int res=1;
    int ans=0;
    rep(i,1,n) {
        res--;
        if(res<n-i) {
            ans+=(min(n-i,v)-res)*i;
            res=min(n-i,v);
        }
    }
    printf("%d\n",ans);
    return 0;
}