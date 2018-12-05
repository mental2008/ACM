#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef double db;
const int maxn=1e5+5;
int n,k;
priority_queue<int,vector<int>,greater<int> >q;

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) {
        int val;
        scanf("%d",&val);
        q.push(val);
    }
    int res=0;
    while(k--) {
        if(q.empty()) puts("0");
        else {
            while(!q.empty()&&q.top()-res==0) q.pop();
            if(q.empty()) {
                puts("0");
                continue;
            }
            printf("%d\n",q.top()-res);
            res=q.top();
            q.pop();
        }
    }
    return 0;
}