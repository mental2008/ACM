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

const int maxn=1e5+5;
int py1[maxn],py2[maxn];
int px1[maxn],px2[maxn];
int sumx[maxn],sumy[maxn];
int n,m;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    int T=0;
    while(caseCnt--) {
        scanf("%d%d",&n,&m);
        rep(i,0,m) {
            py1[i]=py2[i]=0;
            px1[i]=px2[i]=0;
        }
        rep(i,1,n) {
            int x,y;
            scanf("%d%d",&x,&y);
            char s[5];
            scanf("%s",s);
            if(s[0]=='N') py2[y+1]++;
            if(s[0]=='S') py1[y-1]++;
            if(s[0]=='E') px2[x+1]++;
            if(s[0]=='W') px1[x-1]++;
            // e[i].output();
        }
        rep(i,1,m) {
            py2[i]+=py2[i-1];
            px2[i]+=px2[i-1];
        }
        per(i,m-1,0) {
            py1[i]+=py1[i+1];
            px1[i]+=px1[i+1];
        }
        rep(i,0,m) {
            sumx[i]=px1[i]+px2[i];
            sumy[i]=py1[i]+py2[i];
        }
        int y=0;
        rep(i,1,m) {
            if(sumy[i]>sumy[y]) y=i;
        }
        int x=0;
        rep(i,1,m) {
            if(sumx[i]>sumx[x]) x=i;
        }
        // printf("%d %d\n",sumx[x],sumy[y]);
        printf("Case #%d: %d %d\n",++T,x,y);
    }
    return 0;
}