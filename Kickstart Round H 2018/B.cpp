#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=5e6+5;

int n;
char s[maxn];
int a[maxn];
int pre[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    rep(T,1,caseCnt) {
        scanf("%d",&n);
        scanf("%s",s+1);
        rep(i,1,n) a[i]=s[i]-'0';
        pre[0]=0;
        rep(i,1,n) pre[i]=pre[i-1]+a[i];
        int len=(n+1)/2;
        int ans=0;
        rep(i,1,n) {
            int r=i+len-1;
            if(r>n) r=n;
            ans=max(ans,pre[r]-pre[i-1]);
        }
        printf("Case #%d: %d\n",T,ans);
    }
    return 0;
}