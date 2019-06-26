#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        int year,month,day;
        int hour,minute,second;
        scanf("%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
        int ans=(hour*3600+minute*60+second)%100;
        ans*=-1;
        ans=(ans%100+100)%100;
        printf("%d\n",ans);
    }
    return 0;
}