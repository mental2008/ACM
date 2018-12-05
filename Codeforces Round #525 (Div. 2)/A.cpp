#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef double db;
const int maxn=105;
int x;

int main() {
    scanf("%d",&x);
    rep(a,1,x) {
        rep(b,1,x) {
            if(a>=b&&a%b==0&&a/b<x&&a*b>x) {
                return 0*printf("%d %d\n",a,b);
            }
        }
    }
    puts("-1");
    return 0;
}