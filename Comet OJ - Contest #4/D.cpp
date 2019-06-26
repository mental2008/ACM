#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

ll calc(ll x) {
    if(x<10) return x;
    int b[20];
    int index=0;
    while(x) {
        b[++index]=x%10;
        x/=10;
    }
    ll res=0;
    per(i,index-1,1) {
        res=res*10+(b[i+1]+b[i])%10;
    }
    return calc(res);
}
ll solve(ll n) {
    ll ans=n/10*45;
    ll res=calc(n/10*10);
    int p=n%10;
    rep(i,0,p) {
        ans+=(res+i)%10;
    }
    return ans;
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}