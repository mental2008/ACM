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
typedef vector<int> vi;

int main() {
    ll x,y,z;
    ll a,b,c;
    while(~scanf("%lld%lld%lld",&x,&y,&z)) {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(x>a) {
            puts("NO");
            continue;
        }
        a-=x;
        if(y>b+a) {
            puts("NO");
            continue;
        }
        ll k=b+a-y;
        if(z>k+c) {
            puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}