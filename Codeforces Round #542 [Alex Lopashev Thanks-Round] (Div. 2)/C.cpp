#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
#define sqr(x) ((x)*(x))
const int maxn=55;
int n;
int r1,c1;
int r2,c2;
struct Node {
    int x,y,d;
    bool flag;
    Node() {}
    Node(int _x,int _y,int _d,bool _flag) {
        x=_x; y=_y; d=_d; flag=_flag;
    }
    bool operator<(const Node& e) const {
        return d>e.d;
    }
};
priority_queue<Node> Q;
bool vis[maxn][maxn][2];
char s[maxn][maxn];
int p[4]={0,0,1,-1};
int q[4]={1,-1,0,0};

int main() {
    scanf("%d",&n);
    scanf("%d%d",&r1,&c1);
    scanf("%d%d",&r2,&c2);
    rep(i,1,n) scanf("%s",s[i]+1);
    Node start(r1,c1,0,1);
    Q.push(start);
    while(!Q.empty()) {
        Node node=Q.top();
        Q.pop();
        if(node.x==r2&&node.y==c2) {
            printf("%d\n",node.d);
            break;
        }
        if(vis[node.x][node.y][node.flag]) continue;
        vis[node.x][node.y][node.flag]=1;
        if(node.flag) {
            rep(i,1,n) {
                rep(j,1,n) {
                    if(s[i][j]=='1') continue;
                    if(!vis[i][j][0]) {
                        int temp=sqr(i-node.x)+sqr(j-node.y);
                        Q.push(Node(i,j,node.d+temp,0));
                    }
                }
            }
        }
        rep(i,0,3) {
            int x=node.x+p[i];
            int y=node.y+q[i];
            if(x<1||x>n||y<1||y>n||s[x][y]=='1') continue;
            if(vis[x][y][node.flag]) continue;
            Q.push(Node(x,y,node.d,node.flag));
        }
    }
    return 0;
}