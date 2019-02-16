#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=1e5+5;
priority_queue<int,vector<int>,greater<int> > q;
int n;

int main() {
    while(~scanf("%d",&n)) {
        while(!q.empty()) q.pop();
        rep(i,1,n) {
            int val;
            scanf("%d",&val);
            q.push(val);
        }
        while(q.size()>=2) {
            int x=q.top();
            q.pop();
            if(x==0) continue;
            int y=q.top();
            q.pop();
            q.push(x);
            q.push(y%x);
        }
        int ans=q.top();
        printf("%d\n",ans);
    }
    return 0;
}