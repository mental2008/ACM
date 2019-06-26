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
typedef double db;
typedef pair<int,int> pii;

const ll mod=1e9+7;
const int maxn=1005;
int n;
struct point {
    ll x,y;
    point() {}
    point(ll x,ll y):x(x),y(y) {}
    void input() {
        scanf("%lld%lld",&x,&y);
    }
} pt[maxn];

int main() {
    while(~scanf("%d",&n)) {
        rep(i,1,n) pt[i].input();
        
    }
    return 0;
}