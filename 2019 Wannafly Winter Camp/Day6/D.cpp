#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

int a[5];
int b[5];
int z[5];
int ans[5];

bool solve(int i,int j) {
    int sum=a[i]*a[i]-a[j]*a[j]+4*(b[j]-b[i]);
    // if(sum<0) {
    //     swap(i,j);
    //     sum*=-1;
    // }
    if(sum<0) return false;
    for(int y=1;y*y<=sum;++y) {
        if(sum%y==0) {
            int x=sum/y;
            if(x%2==y%2) {
                z[i]=(x+y)/2;
                z[j]=(x-y)/2;
                if((z[i]+a[i])%2==0&&(z[j]+a[j])%2==0) {
                    ans[i]=-(z[i]+a[i])/2;
                    ans[j]=-(z[j]+a[j])/2;
                    printf("%d %d %d\n",ans[1],ans[2],ans[3]);
                    return true;
                }
            }
        }
    }
    if(sum==0) {
        if((a[i]+a[j])%2==0) {
            ans[i]=(-a[i])/2;
            ans[j]=(-a[j])/2;
            printf("%d %d %d\n",ans[1],ans[2],ans[3]);
            return true;
        }
    }
    return false;
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        rep(i,1,3) scanf("%d%d",&a[i],&b[i]);
        bool ok=false;
        mem(ans,0);
        rep(i,1,3) {
            rep(j,1,3) {
                if(i==j) continue;
                if(solve(i,j)) {
                    // printf("%d %d\n",i,j);
                    ok=true;
                    break;
                }
            }
            if(ok) break;
        }
    }
    return 0;
}