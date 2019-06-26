#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=105;
int a[maxn];
int n,m;

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int Max=a[n]+m;
    int res=m;
    rep(i,1,n) {
        res-=a[n]-a[i];
    }
    int Min=a[n];
    if(res>0) {
        Min+=res/n;
        if(res%n!=0) Min++;
    }
    printf("%d %d\n",Min,Max);
    return 0;
}
