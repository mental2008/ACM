#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e6+5;

int n;

int main() {
    scanf("%d",&n);
    if(n==1) {
        return 0*puts("1 0");
    }
    int res=n;
    int ans=0;
    int p=1;
    int sign=0;
    rep(i,2,n) {
        if(res%i==0) {
            int cnt=0;
            while(res%i==0) {
                res/=i;
                cnt++;
            }
            if(ans==0) ans=cnt;
            if(ans!=cnt) sign=1;
            ans=max(ans,cnt);
            p*=i;
        }
    }
    if(ans==1) return 0*printf("%d 0\n",p);
    int q=0;
    res=1;
    while(res<ans) {
        q++;
        res*=2;
    }
    if(res!=ans) sign=1;
    printf("%d %d\n",p,q+sign);
    return 0;
}