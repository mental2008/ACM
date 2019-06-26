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

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll l,r,k;
        scanf("%lld%lld%lld",&l,&r,&k);
        if(k%2==1) {
            printf("%lld\n",r-l+1);
        }
        else {
            ll R=(r+1)/(k+1)*k+(r+1)%(k+1);
            ll L=l/(k+1)*k+l%(k+1);
            // printf("%lld %lld\n",L,R);
            printf("%lld\n",R-L);
        }
    }
    return 0;
}