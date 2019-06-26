#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int maxn=5e5+5;
struct Node {
    int val,start,end;
} v[maxn];
int n;
ll a[maxn];
ll mn[maxn];
ll stmin[maxn][21];
ll stmax[maxn][21];

void init() {
    mn[0]=-1;
    for (int i=1;i<=n;i++)
    {
        mn[i]=((i & (i-1))==0) ? mn[i-1]+1 : mn[i-1];
        stmax[i][0]=stmin[i][0]=a[i];
    }
    for (int j=1;j<=mn[n];j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
        {
            stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
            stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
        }
}
 
ll rmq_max(int L,int R) {
    if(L>R) return 0;
    int k=mn[R-L+1];
    ll res=max(stmax[L][k],stmax[R-(1<<k)+1][k]);
    // printf("%lld %lld\n",a[R],res);
    return min(a[R]-res,0ll);
}
 
ll rmq_min(int L,int R) {
    if(L>R) return 0;
    int k=mn[R-L+1];
    ll res=min(stmin[L][k],stmin[R-(1<<k)+1][k]);
    return min(res-a[L-1],0ll);
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d",&v[i].val);
        if(i==1) a[i]=v[i].val;
        else a[i]=a[i-1]+v[i].val;
        v[i].start=i;
        v[i].end=i;
    }
    // rep(i,1,n) printf("%lld\n",a[i]);
    v[n+1].val=0;
    v[n+1].start=n;
    v[n+1].end=n;
    init();
    stack<int> s;
    int i=1;
    while(i<=n+1){
        if(s.empty()||v[i].val>v[s.top()].val) {
            if(!s.empty()) v[i].start=s.top()+1;
            s.push(i);
            ++i;
        }
        else{
            v[s.top()].end=i-1;
            v[i].start=v[s.top()].start;
            s.pop();
        }
    }
    ll res=0;
    rep(i,1,n) {
        res=max(res,1ll*v[i].val*(a[v[i].end]-a[v[i].start-1]));
        // printf("%d %d %d %lld\n",v[i].val,v[i].start,v[i].end,1ll*v[i].val*(a[v[i].end]-a[v[i].start-1]));
    }
    rep(i,1,n) {
        ll p=(rmq_max(v[i].start,i-1)+rmq_min(i+1,v[i].end)+v[i].val)*v[i].val;
        // printf("%d %lld %d %d %lld %lld\n",i,p,v[i].start,v[i].end,rmq_max(v[i].start,i-1),rmq_min(i+1,v[i].end));
        res=max(p,res);
    }
    printf("%lld\n",res);
    return 0;
}