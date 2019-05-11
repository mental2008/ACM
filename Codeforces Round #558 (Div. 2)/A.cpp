#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
typedef vector<int> vi;
const db exps=1e-8;
const db pi=acos(-1.0);

const int maxn=1005;
bool vis[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<=1) puts("1");
    else if(m==n) puts("0");
    else {
        m-=2;
        rep(i,0,n-1) vis[i]=1;
        vis[0]=vis[2]=0;
        for(int i=4;i<n;i+=2) {
            if(m==0) break;
            vis[i]=0;
            m--;
        }
        rep(i,0,n-1) {
            if(m==0) break;
            if(vis[i]) {
                vis[i]=0;
                m--;
            }
        }
        int ans=0;
        rep(i,0,n-1) {
            if(vis[i]) {
                int j=i;
                for(;j<n;++j) {
                    if(!vis[j]) break;
                }
                ans++;
                i=j;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}