#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=1e5+5;
int n;
int p[maxn];
int q[maxn];

int main() {
    while(~scanf("%d",&n)) {
        rep(i,1,n) scanf("%d",&q[i]);
        mem(p,0);
        int index=0;
        rep(i,1,n) {
            int j=i;
            for(;j<n;++j) {
                if(q[j]>q[j+1]) {
                    break;
                }
            }
            p[q[i]]=++index;
            // printf("%d %d\n",i,j);
            i=j;
        }
        rep(i,1,n) {
            if(!p[i]) p[i]=++index;
        }
        rep(i,1,n) {
            printf("%d%c",p[i],i==n?'\n':' ');
        }
    }
    return 0;
}