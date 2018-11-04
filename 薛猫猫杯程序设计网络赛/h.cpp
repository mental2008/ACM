#include<iostream>
#include<cstdio>
#include<cstring>
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
const ll mod=1e9+7;
const int maxn=505;
int n,m;
char ch[maxn][maxn];
bool vis[maxn][maxn];
ll cnt[maxn][maxn];
ll ans[maxn][maxn];
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
int p[4]={0,0,1,-1};
int q[4]={1,-1,0,0};

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d%d",&n,&m);
        rep(i,0,n-1) {
            scanf("%s",ch[i]);
        }
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        mem(ans,-1);
        ans[0][0]=0;
        mem(vis,0);
        mem(cnt,0);
        cnt[0][0]=1;
        vis[0][0]=1;
        while(!Q.empty()) Q.pop();
        Node start(0,0,0);
        Q.push(start);
        bool ok=false;
        while(!Q.empty()) {
            Node node=Q.front();
            Q.pop();
            if(node.x==x&&node.y==y) {
                ok=true;
                break;
            }
            rep(i,0,3) {
                int xx=node.x+p[i];
                int yy=node.y+q[i];
                if(xx<0||xx>=n||yy<0||yy>m) continue;
                if(ch[xx][yy]=='*') continue;
                if(ans[xx][yy]==-1) {
                    ans[xx][yy]=node.step+1;
                }
                else if(ans[xx][yy]<node.step+1) continue;
                cnt[xx][yy]=(cnt[node.x][node.y]+cnt[xx][yy])%mod;
                if(vis[xx][yy]) continue;
                vis[xx][yy]=1;
                Node temp(xx,yy,node.step+1);
                Q.push(temp);
            }
        }
        if(ok) printf("%lld\n",cnt[x][y]);
        else puts("-1");
    }
    return 0;
}