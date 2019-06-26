#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;
int prim[maxn];
bool vis[maxn];
int cnt;

void init() {
    mem(vis,0);
    cnt=0;
    rep(i,2,maxn-1) {
        if(vis[i]==0) {
            prim[++cnt]=i;
            for(int j=i*2;j<maxn;j+=i) {
                vis[j]=1;
            }
        }
    }
}

ll n;
ll ans;

void solve(ll res) {
    if(res==0) return;
    if(res%2==0) {
        ans+=res/2ll;
        return;
    }
    rep(i,1,cnt) {
        if(res%prim[i]==0) {
            ans++;
            solve(res-prim[i]);
            return;
        }
    }
    ans+=1;
}

int main() {
    init();
    while(~scanf("%lld",&n)) {
        ans=0;
        solve(n);
        printf("%lld\n",ans);
    }
    return 0;
}