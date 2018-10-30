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
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int maxn=15;
int n;
int a[maxn][maxn];
bool vis[maxn][maxn][3][105][105];
int kp[8]={2,1,-1,-2,-1,-2,1,2};
int kq[8]={1,2,2,1,-2,-1,-2,-1};
int bp[4]={1,1,-1,-1};
int bq[4]={1,-1,1,-1};
int rp[4]={1,-1,0,0};
int rq[4]={0,0,1,-1};

struct Node {
    int x,y;
    int state;
    int flag;
    int step;
    int cost;
    Node() {}
    Node(int _x,int _y,int _state,int _flag,int _step,int _cost) {
        x=_x;
        y=_y;
        state=_state;
        flag=_flag;
        step=_step;
        cost=_cost;
    }
    bool operator<(const Node& e)const {
        return step>e.step;
    }
};
priority_queue<Node> Q;

int main() {
    scanf("%d",&n);
    int sx,sy;
    rep(i,1,n) {
        rep(j,1,n) {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1) {
                sx=i;
                sy=j;
            }
        }
    }
    mem(vis,0);
    while(!Q.empty()) Q.pop();
    Node s1(sx,sy,0,1,0,0);
    Node s2(sx,sy,1,1,0,0);
    Node s3(sx,sy,2,1,0,0);
    vis[sx][sy][0][1][0]=1;
    vis[sx][sy][1][1][0]=1;
    vis[sx][sy][2][1][0]=1;
    Q.push(s1);
    Q.push(s2);
    Q.push(s3);
    int ans=inf,cc=inf;
    while(!Q.empty()) {
        Node x=Q.top();
        Q.pop();
        // cout<<x.x<<" "<<x.y<<" "<<x.state<<" "<<x.flag<<" "<<x.step<<" "<<x.cost<<endl;
        if(x.flag==n*n) {
            if(x.step<ans) {
                ans=x.step;
                cc=x.cost;
            }
            else if(x.step==ans&&x.cost<cc) {
                cc=x.cost;
            }
        }
        if(x.state==0) {
            rep(i,0,7) {
                int xx=x.x+kp[i],yy=x.y+kq[i];
                if(xx<1||xx>n||yy<1||yy>n) continue;
                int temp;
                if(a[xx][yy]==x.flag+1) temp=x.flag+1;
                else temp=x.flag;
                if(vis[xx][yy][x.state][temp][x.cost]) continue;
                vis[xx][yy][x.state][temp][x.cost]=1;
                Node node(xx,yy,x.state,temp,x.step+1,x.cost);
                Q.push(node);
            }
        }
        else if(x.state==1) {
            rep(i,0,3) {
                int xx=x.x+bp[i],yy=x.y+bq[i];
                while(1) {
                    if(xx<1||xx>n||yy<1||yy>n) break;
                    int temp;
                    if(a[xx][yy]==x.flag+1) temp=x.flag+1;
                    else temp=x.flag;
                    if(vis[xx][yy][x.state][temp][x.cost]) {
                        xx+=bp[i];
                        yy+=bq[i];
                        continue;
                    }
                    vis[xx][yy][x.state][temp][x.cost]=1;
                    Node node(xx,yy,x.state,temp,x.step+1,x.cost);
                    Q.push(node);
                    xx+=bp[i];
                    yy+=bq[i];
                }
            }
        }
        else {
            rep(i,0,3) {
                int xx=x.x+rp[i],yy=x.y+rq[i];
                while(1) {
                    if(xx<1||xx>n||yy<1||yy>n) break;
                    int temp;
                    if(a[xx][yy]==x.flag+1) temp=x.flag+1;
                    else temp=x.flag;
                    if(vis[xx][yy][x.state][temp][x.cost]) {
                        xx+=rp[i];
                        yy+=rq[i];
                        continue;
                    }
                    vis[xx][yy][x.state][temp][x.cost]=1;
                    Node node(xx,yy,x.state,temp,x.step+1,x.cost);
                    Q.push(node);
                    xx+=rp[i];
                    yy+=rq[i];
                }
            }
        }
        if(x.cost>100) continue;
        rep(i,0,2) {
            if(i==x.state) continue;
            if(vis[x.x][x.y][i][x.flag][x.cost+1]) continue;
            vis[x.x][x.y][i][x.flag][x.cost+1]=1;
            Node node(x.x,x.y,i,x.flag,x.step+1,x.cost+1);
            Q.push(node);
        }
    }
    printf("%d %d\n",ans,cc);
    return 0;
}
