#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=1e6+5;
int n;

int ans=24;
int a[]={0,14,24,9,19};

int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}

int main() {
    scanf("%d",&n);
    default_random_engine e;
    uniform_int_distribution<unsigned> u(1,n);
    int l=0,r=1e9;
    while(l<r) {
        int mid=(l+r)>>1;
        printf("> %d\n",mid);
        fflush(stdout);
        int res;
        scanf("%d",&res);
        bool state=res==1;
        // bool state;
        // if(ans>mid) state=true;
        // else state=false;
        if(state) {
            l=mid+1;
        }
        else {
            r=mid;
        }
    }
    int d=0;
    int cnt=30;
    while(cnt--) {
        printf("? %d\n",u(e));
        fflush(stdout);
        int x;
        scanf("%d",&x);
        // x=a[u(e)];
        // cout<<x<<"\n";
        if(d==0) {
            d=r-x;
        }
        else {
            d=gcd(r-x,d);
        }
    }
    printf("! %d %d\n",r-(n-1)*d,d);
    fflush(stdout);
    return 0;
}