#include <bits/stdc++.h>

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
typedef vector<int> vi;

ll cnt[4];

int main() {
    rep(i,0,3) scanf("%lld",&cnt[i]);
    if(cnt[0]==0&&cnt[2]>0) puts("0");
    else {
        if(cnt[0]==cnt[3]) puts("1");
        else puts("0");
    }
    return 0;
}