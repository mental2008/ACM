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
const ll mod=1e9+7;
const int maxn=1005;
int n,m,k;
int cnt[maxn][maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d%d%d",&n,&m,&k);
        mem(cnt,0);
        rep(i,1,n) {
            rep(j,1,m) {
                int val;
                scanf("%d",&val);
                if(val==0) cnt[i][j]=1;
            }
        }
        rep(i,1,n) {
            rep(j,1,m) {
                cnt[i][j]+=cnt[i][j-1];
            }
        }
        rep(i,1,n) {
            rep(j,1,m) {
                cnt[i][j]+=cnt[i-1][j];
            }
        }
        bool ok=false;
        rep(i,1,n) {
            rep(j,1,m) {
                if(i>=k&&j>=k) {
                    if(k*k==cnt[i][j]+cnt[i-k][j-k]-cnt[i][j-k]-cnt[i-k][j]) {
                        ok=true;
                    }
                }
            }
        }
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}