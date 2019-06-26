#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
int n;
int ans[maxn];
bool vis[maxn];
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}

int main() {
    while(~scanf("%d",&n)) {
        mem(vis,0);
        int res=1,index=0;
        while(1) {
            int k=(n+res)/(2*res);
            if(k==0|index+3>n) break;
            rep(i,1,k) {
                vis[i*2*res-res]=1;
                ans[++index]=res;
                if(index+3>n) break;
            }
            res<<=1;
        }
        vector<int> vec;
        rep(i,1,n) {
            if(!vis[i]) vec.pb(i);
        }
        if(vec.size()==3) {
            ans[++index]=gcd(vec[0],gcd(vec[1],vec[2]));
            ans[++index]=gcd(vec[0],vec[2]);
            ans[++index]=vec[2];
        }
        else if(vec.size()==2) {
            ans[++index]=gcd(vec[0],vec[1]);
            ans[++index]=vec[1];
        }
        else {
            ans[++index]=vec[0];
        }
        rep(i,1,n) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}
