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
ll b[maxn];
int n,m,k;
vector<ll> vec;

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n) scanf("%lld",&b[i]);
    rep(i,1,n-1) {
        vec.pb(b[i+1]-b[i]-1);
    }
    ll sum=n;
    int need=n;
    sort(vec.begin(),vec.end());
    for(auto x:vec) {
        if(need==k) break;
        sum+=x;
        need--;
    }
    printf("%lld\n",sum);
    return 0;
}