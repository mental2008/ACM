#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=5005;
int n;
char c[maxn];
char a[maxn];
bool vis[maxn];
vi vec;

int main() {
    scanf("%d",&n);
    scanf("%s",c+1);
    scanf("%s",a+1);
    int x=0;
    int y=0;
    int z=0;
    int d=0;
    rep(i,1,n) {
        if(c[i]=='1'&&a[i]=='0') x++;
        else if(c[i]=='0'&&a[i]=='1') y++;
        else if(c[i]=='1'&&a[i]=='1') z++;
        else d++;
    }
    bool ok=false;
    rep(i,0,x) {
        rep(j,0,y) {
            if((y+z-i-j)%2==0) {
                int k=y+z-i-j;
                k/=2;
                int dd=(n/2)-i-j-k;
                if(k>=0&&k<=z&&dd>=0&&dd<=d) {
                    ok=true;
                    rep(t,1,n) {
                        if(c[t]=='1'&&a[t]=='0'&&i>0) {
                            vis[t]=1;
                            i--;
                        }
                        if(c[t]=='0'&&a[t]=='1'&&j>0) {
                            vis[t]=1;
                            j--;
                        }
                        if(c[t]=='1'&&a[t]=='1'&&k>0) {
                            vis[t]=1;
                            k--;
                        }
                        if(c[t]=='0'&&a[t]=='0'&&dd>0) {
                            vis[t]=1;
                            dd--;
                        }
                    }
                    rep(t,1,n) if(vis[t]) printf("%d ",t);
                    puts("");
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    if(!ok) puts("-1");
    return 0;
}