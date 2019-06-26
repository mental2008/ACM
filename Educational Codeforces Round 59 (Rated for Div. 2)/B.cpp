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
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1005;


int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll k,x;
        scanf("%lld%lld",&k,&x);
        printf("%lld\n",9*k+x-9);
    }
    return 0;
}