#include<bits/stdc++.h>

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
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=105;
int n;
int a[maxn];

bool judge(int k) {
    ll res=0;
    rep(i,1,n) res+=a[i];
    ll sum=0;
    rep(i,1,n) sum+=(k-a[i]);
    return sum>res;
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int l=0,r=inf;
    rep(i,1,n) {
        l=max(l,a[i]);
    }
    int ans;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(judge(mid)) {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
