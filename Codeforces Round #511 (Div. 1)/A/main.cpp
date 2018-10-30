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
const int maxn=3e5+5;
int n;
int a[maxn];
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
vector<int> vec;
bool vis[4005];
vector<int> prim;
map<int,int> st;

void init() {
    mem(vis,0);
    prim.clear();
    rep(i,2,4000) {
        if(!vis[i]) {
            prim.push_back(i);
        }
        int len=(int)prim.size();
        for(int j=0;j<len&&1ll*prim[j]*i<=4000;++j) {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }
}

int main() {
    init();
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int g=0;
    rep(i,1,n) g=gcd(a[i],g);
    rep(i,1,n) {
        if(a[i]!=g) {
            vec.push_back(a[i]/g);
        }
    }
    st.clear();
    int len=(int)vec.size();
    if(len==0) puts("-1");
    else {
        int cnt=(int)prim.size();
        rep(i,0,len-1) {
            int temp=vec[i];
            rep(j,0,cnt-1) {
                if(temp<prim[j]) break;
                if(temp%prim[j]==0) {
                    st[prim[j]]++;
                    while(temp%prim[j]==0) temp/=prim[j];
                }
            }
            if(temp!=1) st[temp]++;
        }
        int num=0;
        int sum=0;
        for(auto it:st) {
            if(it.se>sum) {
                sum=it.se;
                num=it.fi;
            }
        }
        int ans=0;
        rep(i,0,len-1) {
            if(vec[i]%num==0) ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
