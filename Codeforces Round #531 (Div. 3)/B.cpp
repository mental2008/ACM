#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=5005;
int n,k;
int a[maxn];
int c[maxn];
set<int> st[maxn];

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,k) st[i].clear();
    int cnt=0;
    rep(i,1,n) {
        bool ok=false;
        if(k-cnt==n-i+1) {
            st[++cnt].insert(a[i]);
            c[i]=cnt;
            continue;
        }
        rep(j,1,k) {
            if(st[j].find(a[i])==st[j].end()) {
                if(st[j].empty()) cnt++;
                ok=true;
                st[j].insert(a[i]);
                c[i]=j;
                break;
            }
        }
        if(!ok) {
            return 0*puts("NO");
        }
    }
    puts("YES");
    rep(i,1,n) {
        printf("%d ",c[i]);
    }
    puts("");
    return 0;
}