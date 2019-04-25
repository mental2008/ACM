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

int a[33];
int cnt;
vi ans;
bool judge() {
    rep(i,0,cnt-1) if(a[i]==0) return false;
    return true;
}

int main() {
    int x;
    scanf("%d",&x);
    int temp=x;
    cnt=0;
    while(temp) {
        a[cnt++]=(temp&1);
        temp>>=1;
    }
    while(1) {
        // per(i,cnt-1,0) printf("%d",a[i]);
        // puts("");
        if(judge()) break;
        if(a[0]==0) {
            a[0]=1;
            ans.pb(0);
        }
        else {
            per(i,cnt-1,0) {
                if(a[i]==0) {
                    ans.pb(i+1);
                    rep(j,1,i) a[j]^=1;
                    break;
                }
            }
        }
    }
    int len=(int)ans.size();
    printf("%d\n",len*2);
    rep(i,0,len-1) printf("%d ",ans[i]);
    if(len!=0) puts("");
    return 0;
}