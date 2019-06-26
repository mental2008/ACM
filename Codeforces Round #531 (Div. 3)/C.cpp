#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
const int maxn=1e5+5;
int n,x,y;
int a[maxn];
vector<int> vec;

int main() {
    scanf("%d%d%d",&n,&x,&y);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) vec.pb(a[i]);
    if(x>y) printf("%d\n",n);
    else {
        int ans=0;
        while(1) {
            sort(vec.begin(),vec.end());
            bool ok=false;
            rep(i,0,n-1) {
                if(vec[i]!=0) {
                    if(vec[i]<=x) {
                        ans++;
                        ok=true;
                        vec[i]=0;
                    }
                    break;
                }
            }
            if(!ok) break;
            sort(vec.begin(),vec.end());
            rep(i,0,n-1) {
                if(vec[i]!=0) {
                    vec[i]=vec[i]+y;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}