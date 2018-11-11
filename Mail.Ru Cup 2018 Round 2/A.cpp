#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include<cmath>

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
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1005;
int n,s;
int a[maxn];
int b[maxn];
bool vis[maxn];

int main() {
    while(~scanf("%d%d",&n,&s)) {
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) scanf("%d",&b[i]);
        mem(vis,0);
        if(a[1]==0) {
            puts("NO");
            continue;
        }
        rep(i,1,n) {
            if(a[i]==1) vis[i]=1;
        }
        bool sign=false;
        per(i,n,1) {
            if(b[i]==1&&vis[i]) {
                sign=true;
            }
            if(sign&&b[i]) {
                vis[i]=1;
            }
        }
        if(vis[s]) puts("YES");
        else puts("NO");
    }
    return 0;
}