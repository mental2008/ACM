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

ll n,l;

int main() {
    scanf("%lld%lld",&n,&l);
    ll x=n-l,y=l;
    if(x%2==0&&y%2==1) {
        printf("%lld\n",min(x,y));
    }
    else if(x%2==0&&y%2==0) {
        printf("%lld\n",x);
    }
    else if(x%2==1&&y%2==1) {
        printf("%lld\n",y);
    }
    else {
        puts("Impossible");
    }
    return 0;
}