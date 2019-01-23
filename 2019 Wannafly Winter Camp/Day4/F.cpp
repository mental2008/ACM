#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=1e6+5;
int n,m;
int sx,sy;
int ex,ey;

int main() {
    scanf("%d%d",&n,&m);
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&ex,&ey);
    if(n>m) {
        swap(n,m);
        swap(sx,sy);
        swap(ex,ey);
    }
    if(n>=3) {
        if(m>=4) {
            if((sx%2==sy%2)!=(ex%2==ey%2)) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
        else {
            if((sx==2&&sy==2)||(ex==2&&ey==2)) {
                puts("No");
            }
            else if((sx%2==sy%2)!=(ex%2==ey%2)) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }
    else {
        if(abs(ex-sx)==1&&abs(ey-sy)%2==0&&abs(ey-sy)%4!=0) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    return 0;
}