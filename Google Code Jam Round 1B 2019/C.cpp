#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=10005;
int n,k;
int c[maxn],d[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    int T=0;
    while(caseCnt--) {
        scanf("%d%d",&n,&k);
        rep(i,1,n) scanf("%d",&c[i]);
        rep(i,1,n) scanf("%d",&d[i]);
        int ans=0;
        rep(i,1,n) {
            rep(j,i,n) {
                int p=0,q=0;
                rep(k,i,j) {
                    p=max(p,c[k]);
                    q=max(q,d[k]);
                }
                if(abs(p-q)<=k) ans++;
            }
        }
        printf("Case #%d: %d\n",++T,ans);
    }
    return 0;
}