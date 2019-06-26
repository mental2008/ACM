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

const int maxn=2e5+5;
int n;
ll a[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    int ans=0;
    rep(i,2,n) {
        if(a[i-1]==a[i]) ans++;
    }
    rep(i,2,n-1) {
        if(a[i-1]>a[i]&&a[i+1]>a[i]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}