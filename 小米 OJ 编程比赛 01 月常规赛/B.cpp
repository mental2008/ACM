#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=405;
int n,m;
int e[maxn][maxn];
bool vis[maxn][maxn];
struct Node {
    int x,y;
    int step;
    Node() {}
    Node(int _x,int _y,int _step) {
        x=_x;
        y=_y;
        step=_step;
    }
};
queue<Node> Q;

int main() {
    scanf("%d%d",&n,&m);
    mem(e,0);
    rep(i,1,n) e[i][i]=0x3f3f3f3f;
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u][v]=1;
        e[v][u]=1;
    }
    Node start(1,1,0);
    mem(vis,0);
    vis[1][1]=1;
    Q.push(start);
    while(!Q.empty()) {
        Node node=Q.front();
        Q.pop();
        if(node.x==n&&node.y==n) {
            printf("%d\n",node.step);
            return 0;
        }
        rep(i,1,n) {
            rep(j,1,n) {
                if(i==j&&i!=n) continue;
                if(e[node.x][i]==1&&e[node.y][j]==0) {
                    if(vis[i][j]) continue;
                    // printf("%d %d\n",node.x,i);
                    vis[i][j]=1;
                    Node temp(i,j,node.step+1);
                    Q.push(temp);
                }
            }
        }
    }
    puts("-1");
    return 0;
}