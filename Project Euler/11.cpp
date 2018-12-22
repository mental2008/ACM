#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=20;
int a[maxn][maxn];

int main() {
    freopen("11.in","r",stdin);
    for(int i=0;i<maxn;++i) {
        for(int j=0;j<maxn;++j) {
            scanf("%d",&a[i][j]);
            // printf("%d ",a[i][j]);
        }
        // puts("");
    }
    ll ans=0;
    for(int i=0;i<maxn;++i) {
        for(int j=0;j<maxn;++j) {
            ll res;
            if(i+3<maxn&&j+3<maxn) {
                res=1;
                for(int k=0;k<4;++k) {
                    res*=a[i+k][j+k];
                }
                ans=max(ans,res);
            }
            if(i+3<maxn&&j-3>=0) {
                res=1;
                for(int k=0;k<4;++k) {
                    res*=a[i+k][j-k];
                }
                ans=max(ans,res);
            }
            if(i+3<maxn) {
                res=1;
                for(int k=0;k<4;++k) {
                    res*=a[i+k][j];
                }
                ans=max(ans,res);   
            }
            if(j+3<maxn) {
                res=1;
                for(int k=0;k<4;++k) {
                    res*=a[i][j+k];
                }
                ans=max(ans,res);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}