#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>

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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);

int n,S;

int main() {
    scanf("%d%d",&n,&S);
    if(S<=n) puts("1");
    else {
        int ans;
        if(S%n==0) ans=S/n;
        else ans=S/n+1;
        printf("%d\n",ans);
    }
    return 0;
}