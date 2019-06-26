#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define MP make_pair
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=14;
struct point {
    int value;
    int type;
} pt[maxn];
char s[5];
void input(int i) {
    pt[i].value=s[0]-'0';
    if(s[1]=='m') pt[i].type=0;
    if(s[1]=='s') pt[i].type=1;
    if(s[1]=='p') pt[i].type=2;
    if(s[1]=='z') pt[i].type=3;
}
int cnt[10][4];
bool dfs(int x,int y,int sum) {
    if(sum==2) {
        rep(i,0,2) {
            rep(j,1,9) {
                if(cnt[j][i]==2) return true;
            }
        } // wan tiao tong
        rep(i,1,7) {
            if(cnt[i][3]==2) return true;
        } // zi
        return false;
    }
    // y
    if(y<=2) {
        rep(i,x,9) {
            if(i<=7&&cnt[i][y]>=1&&cnt[i+1][y]>=1&&cnt[i+2][y]>=1) {
                cnt[i][y]--; cnt[i+1][y]--; cnt[i+2][y]--;
                if(dfs(i,y,sum-3)) return true;
                cnt[i][y]++; cnt[i+1][y]++; cnt[i+2][y]++;
            }
            if(cnt[i][y]>=3) {
                cnt[i][y]-=3;
                if(dfs(x,y,sum-3)) return true;
                cnt[i][y]+=3;
            }
        }
    }
    else {
        rep(i,x,7) {
            if(cnt[i][y]>=3) {
                cnt[i][y]-=3;
                if(dfs(i,y,sum-3)) return true;
                cnt[i][y]+=3;
            }
        }
    }
    if(y+1<=3) {
        return dfs(1,y+1,sum);
    }
    return false;
}
bool judge() {
    mem(cnt,0);
    rep(i,0,13) {
        cnt[pt[i].value][pt[i].type]++;
    }
    rep(i,0,2) {
        rep(j,1,9) {
            if(cnt[j][i]>4) return false;
        }
    } // wan tiao tong
    rep(i,1,7) {
        if(cnt[i][3]>4) return false;
    } // zi
    rep(i,1,7) {
        if(cnt[i][3]==1||cnt[i][3]==4) return false;
    } // zi
    int sum=14;
    return dfs(1,0,sum);
}

int main() {
    while(~scanf("%s",s)) {
        input(0);
        rep(i,1,12) {
            scanf("%s",s);
            input(i);
        }
        rep(i,1,9) {
            char t[5];
            t[0]='0'+i;
            t[1]='m';
            t[2]='\0';
            strcpy(s,t);
            input(13);
            if(judge()) {
                printf("%s\n",t);
            }
        }
        rep(i,1,9) {
            char t[5];
            t[0]='0'+i;
            t[1]='s';
            t[2]='\0';
            strcpy(s,t);
            input(13);
            if(judge()) {
                printf("%s\n",t);
            }
        }
        rep(i,1,9) {
            char t[5];
            t[0]='0'+i;
            t[1]='p';
            t[2]='\0';
            strcpy(s,t);
            input(13);
            if(judge()) {
                printf("%s\n",t);
            }
        }
        rep(i,1,7) {
            char t[5];
            t[0]='0'+i;
            t[1]='z';
            t[2]='\0';
            strcpy(s,t);
            input(13);
            if(judge()) {
                printf("%s\n",t);
            }
        }
    }
    return 0;
}