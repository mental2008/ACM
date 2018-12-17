#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=1e5+5;
int n;
int a[maxn];
int num[maxn];
int vis[maxn];
int b[maxn];
int cnt=0;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    // if(n==2&&a[1]==1&&a[2]==1) return 0*puts("Possible\n1 2");
    rep(i,1,n) {
        if(!vis[a[i]]||num[vis[a[i]]]==n-a[i]) vis[a[i]]=++cnt;
        b[i]=vis[a[i]];
        num[b[i]]++;
    }
    rep(i,1,n) {
        if(a[i]!=n-num[b[i]]) {
            return 0*puts("Impossible");
        }
    }
    puts("Possible");
    rep(i,1,n) {
        printf("%d%c",b[i],(i==n?'\n':' '));
    }
    return 0;
}