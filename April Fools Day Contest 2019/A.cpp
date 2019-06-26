#include <bits/stdc++.h>

using namespace std;

const int maxn=20;
int n;
int a[maxn];
int solve(int l,int r) {
    if(l==r) return 1;
    bool ok=true;
    for(int i=l;i<r;++i) {
        if(a[i]>a[i+1]) {
            ok=false;
            break;
        }
    }
    if(ok) return r-l+1;
    int mid=(l+r)>>1;
    return max(solve(l,mid),solve(mid+1,r));
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    printf("%d\n",solve(1,n));
    return 0;
}