#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+5;
int prim[maxn];
bool vis[maxn];
int mu[maxn];
int cnt;

void init() {
    mu[1]=1;
    for(int i=2;i<maxn;++i) {
        if(!vis[i]) {
            prim[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt&&prim[j]*i<maxn;++j) {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
            else mu[prim[j]*i]=-mu[i];
        }
    }
}

int main() {
    init();
    int n=10000;
    int ans=0;
    for(int i=2;i<=n;++i) {
        for(int j=1;j<=cnt;++j) {
            if(i%prim[j]==0) {
                ans+=-mu[i]*(n/i)*prim[j];
                // printf("%d %d %d\n",i,mu[i],prim[j]);
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}