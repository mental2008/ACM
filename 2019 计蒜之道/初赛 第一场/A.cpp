#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=5005;
int n;
vector<int> e[maxn];
int fa[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n-1) {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        fa[y]=x;
    }
    int ans=0;
    rep(i,1,n) {
        rep(j,i+1,n) {
            if(i==1) {
                if(fa[j]==i) {
                    ans=max(ans,(int)e[i].size()-1+(int)e[j].size());
                }
                else {
                    ans=max(ans,(int)e[i].size()+(int)e[j].size());
                }
            }
            else {
                if(fa[j]==i) {
                    ans=max(ans,(int)e[i].size()+(int)e[j].size());
                }
                else {
                    ans=max(ans,1+(int)e[i].size()+(int)e[j].size());
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}