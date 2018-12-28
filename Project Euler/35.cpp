#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;
bool vis[maxn];
int a[10];
int cnt;

bool judge(int x) {
    cnt=0;
    while(x) {
        a[++cnt]=x%10;
        x/=10;
    }
    for(int i=1;i<=cnt;++i) {
        int y=0;
        for(int j=i;j<=cnt;++j) {
            y=y*10+a[j];
        }
        for(int j=1;j<i;++j) {
            y=y*10+a[j];
        }
        if(vis[y]) return false;
    }
    return true;
}

int main() {
    vis[1]=1;
    for(int i=2;i<maxn;++i) {
        if(!vis[i]) {
            for(int j=2*i;j<maxn;j+=i) {
                vis[j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=1000000;++i) {
        if(judge(i)) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}