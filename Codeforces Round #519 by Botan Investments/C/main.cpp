#include<bits/stdc++.h>

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
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1005;
char s[maxn];
int ans[maxn];
int n;
struct Node {
    int kind;
    int pos;
    Node() {}
    Node(int _kind,int _pos) {
        kind=_kind;
        pos=_pos;
    }
};
deque<Node> Q;

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    rep(i,1,n) ans[i]=0;
    rep(i,1,n) {
        int j;
        for(j=i;j<=n;++j) {
            if(s[j]!=s[i]) {
                break;
            }
        }
        Node node(s[i]-'a',j-1);
        Q.push_back(node);
        i=j-1;
    }
    while(!Q.empty()) {
        Node node=Q.front();
        Q.pop_front();
        if(Q.empty()&&node.kind==1) {
            break;
        }
        ans[node.pos]=1;
    }
    rep(i,1,n) {
        printf("%d%c",ans[i],(i==n?'\n':' '));
    }
    return 0;
}
