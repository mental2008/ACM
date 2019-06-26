#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=105;
int n;

int main() {
    scanf("%d",&n);
    int pos=0;
    int neg=0;
    rep(i,1,n) {
        int a; scanf("%d",&a);
        if(a>0) pos++;
        if(a<0) neg++;
    }
    int m=(n+1)/2;
    if(pos>=m) puts("1");
    else if(neg>=m) puts("-1");
    else puts("0");
    return 0;
}