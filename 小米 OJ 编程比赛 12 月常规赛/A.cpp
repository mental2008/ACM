#include<bits/stdc++.h>

using namespace std;

const int maxn=15;
int a[maxn];
int vis[maxn];

int main() {
    int r;
    int n=0;
    while(~scanf("%d",&r)) {
        a[++n]=r;
    }
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1;i<=n;++i) {
        if(vis[i]) {
            for(int j=1;j<=a[i];++j) {
                vis[i+j]=1;
            }
        }
    }
    if(vis[n]) puts("true");
    else puts("false");
    return 0;
}