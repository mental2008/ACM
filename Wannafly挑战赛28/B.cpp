#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=1e5+5;

char s[maxn];
int n;
int ns[maxn];
int nm[maxn];
int nc[maxn];
deque<int> st;

bool judge(int l,int r) {
    if(nm[r]-nm[l-1]<2) return false;
    if(nc[r]-nc[l-1]<3) return false;
    if(ns[r]-ns[l-1]<1) return false;
    int a=st.front();st.pop_front();
    int b=st.front();st.pop_front();
    st.push_front(b);
    st.push_front(a);
    if(ns[b]-ns[a]) {
        int p=a,q=b;
        int res;
        while(p<=q) {
            int mid=(p+q)>>1;
            if(ns[mid]-ns[p-1]) {
                res=mid;
                q=mid-1;
            }
            else p=mid+1;
        }
        if(nc[r]-nc[res-1]>=3&&nc[r]-nc[b-1]>=2) {
            return true;
        }
    }
    if(ns[r]-ns[b]) {
        int p=b,q=r;
        int res;
        while(p<=q) {
            int mid=(p+q)>>1;
            if(ns[mid]-ns[p-1]) {
                res=mid;
                q=mid-1;
            }
            else p=mid+1;
        }
        if(nc[r]-nc[res-1]>=1&&nc[r]-nc[a-1]>=3) {
            return true;
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d",&n)) {
        scanf("%s",s+1);
        mem(ns,0);
        mem(nm,0);
        mem(nc,0);
        st.clear();
        rep(i,1,n) {
            ns[i]=ns[i-1]+(s[i]=='s');
            nm[i]=nm[i-1]+(s[i]=='m');
            nc[i]=nc[i-1]+(s[i]=='c');
            if(s[i]=='m') st.push_back(i);
        }
        ll ans=0;
        int r=1;
        rep(i,1,n) {
            int l=r;
            r=n;
            int res=-1;
            while(!st.empty()&&st.front()<i) st.pop_front();
            while(l<=r) {
                int mid=(l+r)>>1;
                if(judge(i,mid)) {
                    res=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(res==-1) break;
            r=res;
            ans+=n-r+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
