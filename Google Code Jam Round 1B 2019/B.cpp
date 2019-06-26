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

int cnt[7];
int cnt2[7];
int a[7];

int main() {
    int caseCnt,w;
    scanf("%d%d",&caseCnt,&w);
    while(caseCnt--) {
        int p=210,q=50;
        printf("%d\n",p);
        fflush(stdout);
        ull y;
        scanf("%llu",&y);
        printf("%d\n",q);
        fflush(stdout);
        ull x;
        scanf("%llu",&x);
        rep(i,1,w-2) {
            printf("1\n");
            fflush(stdout);
            ull temp;
            scanf("%llu",&temp);
        }
        rep(i,1,6) {
            cnt[i]=q/i;
            cnt2[i]=p/i;
        }
        a[4]=y/(1<<cnt2[4]);
        y-=a[4]*(1<<cnt2[4]);
        a[5]=y/(1<<cnt2[5]);
        y-=a[5]*(1<<cnt2[5]);
        a[6]=y/(1<<cnt2[6]);
        x-=a[4]*(1<<cnt[4])+a[5]*(1<<cnt[5])+a[6]*(1<<cnt[6]);
        a[1]=x/(1<<cnt[1]);
        x-=a[1]*(1<<cnt[1]);
        a[2]=x/(1<<cnt[2]);
        x-=a[2]*(1<<cnt[2]);
        a[3]=x/(1<<cnt[3]);
        rep(i,1,6) {
            printf("%d ",a[i]);
        }
        puts("");
        fflush(stdout);
    }
    return 0;
}