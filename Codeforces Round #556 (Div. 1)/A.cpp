#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>
#include <complex>
#include <unordered_map>
#include <unordered_set>

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
const db exps=1e-8;
const db pi=acos(-1.0);
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;

const int maxn=4e5+5;
int n;
int a[maxn];
bool vis[maxn];
int prim[maxn];
int cnt;
int b[maxn];

int main() {
    cnt=0;
    rep(i,2,maxn-1) {
        if(!vis[i]) {
            prim[++cnt]=i;
            for(int j=i*2;j<maxn;j+=i) {
                vis[j]=1;
            }
        }
    }
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int x=0,y=0;
    rep(i,1,n) {
        if(a[i]==1) x++;
        else y++;
    }
    int sum=0;
    int id=1;
    rep(i,1,n) {
        while(prim[id]<sum) id++;
        // printf("%d %d\n",id,sum);
        if(prim[id]==sum+1) {
            if(x) {
                b[i]=1;
                x--;
                id++;
            }
            else {
                b[i]=2;
                y--;
            }
        }
        else {
            if(y) {
                b[i]=2;
                y--;
                if(prim[id]==sum+2) id++;
            }
            else {
                b[i]=1;
                x--;
            }
        }
        sum+=b[i];
        // printf("%d\n",sum);
    }
    rep(i,1,n) printf("%d%c",b[i],i==n?'\n':' ');
    return 0;
}