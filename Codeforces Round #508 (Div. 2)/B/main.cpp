#include<bits/stdc++.h>
using namespace std;
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int n;

int main() {
    scanf("%d",&n);
    if(n<=2) puts("No");
    else {
        bool flag=false;
        int sum=n*(n+1)/2;
        int res=0;
        rep(i,2,n) {
            if(sum%i==0) {
                flag=true;
                res=i;
                break;
            }
        }
        if(flag) {
            puts("Yes");
            printf("1 %d\n",res);
            printf("%d",n-1);
            rep(j,1,n) {
                if(j==res) continue;
                printf(" %d",j);
            }
            puts("");
        }
        else {
            puts("No");
        }
    }
    return 0;
}
