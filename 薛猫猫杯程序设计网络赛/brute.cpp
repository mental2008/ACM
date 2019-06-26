#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>

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
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxn=105;
int n;
int Min,Max;
int a[maxn];
void dfs(int depth) {
    bool ok=false;
    rep(i,1,n-2) {
        if(a[i]&&a[i+1]&&a[i+2]) {
            ok=true;
            a[i]--;a[i+1]--;a[i+2]--;
            dfs(depth+1);
            a[i]++;a[i+1]++;a[i+2]++;
        }
    }
    if(!ok) {
        Min=min(Min,depth);
        Max=max(Max,depth);
    }
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        Max=0;
        Min=inf;
        scanf("%d",&n);
        rep(i,1,n) {
            scanf("%d",&a[i]);
        }
        dfs(0);
        printf("%d %d\n",Min,Max);
    }
    return 0;
}