#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>

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
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxn=105;
int n;
int a[maxn];
map<pii,int> st[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,0,n) st[i].clear();
        st[0][mp(0,0)]=1;
        st[1][mp(0,a[1])]=1;
        st[2][mp(a[1],a[2])]=1;
        rep(i,3,n) {
            for(auto it:st[i-1]) {
                int x=it.fi.fi,y=it.fi.se;
                int cnt=it.se;
                int temp=min(x,y);
                temp=min(temp,a[i]);
                y-=temp;
                int val=st[i][mp(y,a[i]-temp)];
                if(val) {
                    st[i][mp(y,a[i]-temp)]=min(val,cnt+temp);
                }
                else {
                    st[i][mp(y,a[i]-temp)]=cnt+temp;
                }
            }
            for(auto it:st[i-2]) {
                int x=it.fi.fi,y=it.fi.se;
                int b=a[i-1],c=a[i];
                int cnt=it.se;
                int add=0;
                int temp=min(b,c);
                temp=min(temp,y);
                add+=temp;
                b-=temp;c-=temp;y-=temp;
                temp=min(x,y);
                temp=min(temp,b);
                add+=temp;
                x-=temp;y-=temp;b-=temp;
                int val=st[i][mp(b,c)];
                if(val) {
                    st[i][mp(b,c)]=min(val,cnt+add);
                }
                else {
                    st[i][mp(b,c)]=cnt+add;
                }
            }
            for(auto it:st[i-3]) {
                int x=it.fi.fi,y=it.fi.se;
                int b=a[i-2],c=a[i-1],d=a[i];
                int cnt=it.se;
                int add=0;
                int temp=min(b,c);
                temp=min(temp,d);
                add+=temp;
                b-=temp;c-=temp;d-=temp;
                temp=min(b,c);
                temp=min(temp,y);
                add+=temp;
                y-=temp;b-=temp;c-=temp;
                temp=min(x,y);
                temp=min(temp,b);
                add+=temp;
                x-=temp;y-=temp;b-=temp;
                int val=st[i][mp(c,d)];
                if(val) {
                    st[i][mp(c,d)]=min(val,cnt+add);
                }
                else {
                    st[i][mp(c,d)]=cnt+add;
                }
            }
            if(i>=4) st[i-4].clear();
        }
        int ans=inf;
        for(auto it:st[n]) {
            ans=min(ans,it.se);
        }
        ans--;
        printf("%d ",ans);
        rep(i,0,n) st[i].clear();
        st[0][mp(0,0)]=1;
        st[1][mp(0,a[1])]=1;
        st[2][mp(a[1],a[2])]=1;
        rep(i,3,n) {
            for(auto it:st[i-1]) {
                int x=it.fi.fi,y=it.fi.se;
                int cnt=it.se;
                int temp=min(x,y);
                temp=min(temp,a[i]);
                y-=temp;
                int val=st[i][mp(y,a[i]-temp)];
                if(val) {
                    st[i][mp(y,a[i]-temp)]=max(val,cnt+temp);
                }
                else {
                    st[i][mp(y,a[i]-temp)]=cnt+temp;
                }
            }
            for(auto it:st[i-2]) {
                int x=it.fi.fi,y=it.fi.se;
                int b=a[i-1],c=a[i];
                int cnt=it.se;
                int add=0;
                int temp=min(b,c);
                temp=min(temp,y);
                add+=temp;
                b-=temp;c-=temp;y-=temp;
                temp=min(x,y);
                temp=min(temp,b);
                add+=temp;
                x-=temp;y-=temp;b-=temp;
                int val=st[i][mp(b,c)];
                if(val) {
                    st[i][mp(b,c)]=max(val,cnt+add);
                }
                else {
                    st[i][mp(b,c)]=cnt+add;
                }
            }
            for(auto it:st[i-3]) {
                int x=it.fi.fi,y=it.fi.se;
                int b=a[i-2],c=a[i-1],d=a[i];
                int cnt=it.se;
                int add=0;
                int temp=min(b,c);
                temp=min(temp,d);
                add+=temp;
                b-=temp;c-=temp;d-=temp;
                temp=min(b,c);
                temp=min(temp,y);
                add+=temp;
                y-=temp;b-=temp;c-=temp;
                temp=min(x,y);
                temp=min(temp,b);
                add+=temp;
                x-=temp;y-=temp;b-=temp;
                int val=st[i][mp(c,d)];
                if(val) {
                    st[i][mp(c,d)]=max(val,cnt+add);
                }
                else {
                    st[i][mp(c,d)]=cnt+add;
                }
            }
            if(i>=4) st[i-4].clear();
        }
        ans=0;
        for(auto it:st[n]) {
            ans=max(ans,it.se);
        }
        ans--;
        printf("%d\n",ans);
    }
    return 0;
}