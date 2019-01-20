#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=15;
const int maxc=1050;
const int INF=0x3f3f3f3f;

int n,m,c;
int T[maxn][maxn];
int xs,xt;
int ys,yt;
bool vis[maxn][maxn][maxc];
int dp[maxn][maxn][maxc];
struct Node {
    int x,y;
    int sugar;
    int step;
    Node() {}
    Node(int _x,int _y,int _sugar,int _step) {
        x=_x;
        y=_y;
        sugar=_sugar;
        step=_step;
    }
    bool operator<(const Node& e) const {
        return step>e.step;
    }
};
priority_queue<Node> Q;

int main() {
    scanf("%d%d%d",&n,&m,&c);
    rep(i,1,n) {
        rep(j,1,m) {
            scanf("%d",&T[i][j]);
        }
    }
    scanf("%d%d%d%d",&xs,&xt,&ys,&yt);
    mem(dp,-1);
    mem(vis,0);
    while(!Q.empty()) Q.pop();
    Node start(xs,xt,0,0);
    Q.push(start);
    while(!Q.empty()) {
        Node node=Q.top();
        Q.pop();
        if(vis[node.x][node.y][min(node.sugar,c)]) continue;
        vis[node.x][node.y][min(node.sugar,c)]=1;
        dp[node.x][node.y][min(node.sugar,c)]=node.step;
        rep(i,1,n) {
            rep(j,1,m) {
                if(i==node.x&&j==node.y) {
                    int p=node.step+1;
                    while(p%T[i][j]!=0) {
                        p++;
                    }
                    Node newnode(i,j,node.sugar+1,p);
                    Q.push(newnode);
                    continue;
                }
                int p=node.step;
                int temp=abs(node.x-i)+abs(node.y-j);
                while((p+temp)%T[i][j]!=0) {
                    temp++;
                }
                Node newnode(i,j,node.sugar+1,p+temp);
                Q.push(newnode);
            }
        }
    }
    int ans=INF;
    rep(i,1,n) {
        rep(j,1,m) {
            ans=min(ans,dp[i][j][c]+abs(i-ys)+abs(j-yt));
            // printf("%d %d %d\n",i,j,dp[i][j][c]);
        }
    }
    printf("%d\n",ans);
    return 0;
}