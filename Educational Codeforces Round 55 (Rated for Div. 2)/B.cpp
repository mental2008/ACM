#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=1e5+5;
int n,m;
char s[maxn];
int a[maxn];
int sumg,sums;

int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    m=0;
    sumg=0;
    rep(i,1,n) {
        sumg+=(s[i]=='G');
    }
    int start=0;
    rep(i,1,n) {
        if(s[i]=='G') {
            start=i;
            break;
        }
    }
    if(start==0) puts("0");
    else {
        rep(i,start,n) {
            int j=i;
            for(;j<=n;++j) {
                if(s[j]!=s[i]) break;
            }
            ++m;
            a[m]=j-i;
            i=j-1;
        }
        int ans=0;
        rep(i,1,m) {
            if(i&1) {
                ans=max(ans,a[i]);
                if(i+2<=m&&a[i+1]==1) {
                    if(a[i]+a[i+2]==sumg) {
                        ans=max(ans,a[i]+a[i+2]);
                    }
                    else {
                        ans=max(ans,a[i]+a[i+2]+1);
                    }
                }
                if(i+2<=m) {
                    ans=max(ans,a[i]+1);
                }
                if(i-2>=1) {
                    ans=max(ans,a[i]+1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}