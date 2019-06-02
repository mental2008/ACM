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
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=20;
int n;
ll a[maxn];
ll b[maxn];
ll gcd(ll x,ll y) {
    return y==0?x:gcd(y,x%y);
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        rep(i,0,n-1) scanf("%lld",&a[i]);
        int ans=0;
        rep(i,1,(1<<n)-1) {
            int cnt=0;
            rep(j,0,n-1) {
                if((i>>j)&1) {
                    b[++cnt]=a[j];
                }
            }
            bool ok=true;
            rep(j,1,cnt) {
                rep(k,j+1,cnt) {
                    if(gcd(b[j],b[k])>1) {
                        ok=false;
                    }
                }
            }
            if(ok) ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}