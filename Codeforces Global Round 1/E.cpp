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

const int maxn=1e5+5;
ll c[maxn];
ll t[maxn];
ll a[maxn];
ll b[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&c[i]);
    rep(i,1,n) scanf("%lld",&t[i]);
    if(c[1]!=t[1]||c[n]!=t[n]) puts("No");
    else {
        rep(i,2,n) {
            a[i]=c[i]-c[i-1];
            b[i]=t[i]-t[i-1];
        }
        sort(a+2,a+1+n);
        sort(b+2,b+1+n);
        bool ok=true;
        rep(i,2,n) {
            if(a[i]!=b[i]) {
                ok=false;
                break;
            }
        }
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}