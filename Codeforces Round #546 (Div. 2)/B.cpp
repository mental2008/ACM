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
typedef vector<int> vi;

const int inf=0x3f3f3f3f;
const int maxn=5005;
int n,k;
int num[maxn];
bool vis[maxn];


int main() {
    scanf("%d%d",&n,&k);
    printf("%d\n",min(k-1,n-k)+3*n);
    return 0;
}