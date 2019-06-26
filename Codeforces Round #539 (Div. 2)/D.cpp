#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=5005;
char s[maxn];
int n;

int solve(int l,int r) {
    int len=r-l+1;
    if(len%2==1) return 2;
    bool ok=false;
    int mid=(l+r)>>1;
    rep(i,l,mid) {
        if(s[i]!=s[mid+i-l+1]) {
            ok=true;
            break;
        }
    }
    if(ok) return 1;
    return solve(l,mid);
}

int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    bool ok=false;
    rep(i,1,n-1) {
        if(s[i]!=s[i+1]) {
            ok=true;
            break;
        }
    }
    if(!ok) puts("Impossible");
    else {
        if(n%2==1) {
            bool ok=false;
            rep(i,1,n/2-1) {
                if(s[i]!=s[i+1]) {
                    ok=true;
                    break;
                }
            }
            if(ok) puts("2");
            else puts("Impossible");
        }
        else printf("%d\n",solve(1,n));
    }
    return 0;
}