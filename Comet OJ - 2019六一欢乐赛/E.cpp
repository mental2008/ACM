#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=20;
int n;
char s[maxn][maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%s",s[i]+1);
    }
    int sx,sy;
    rep(i,1,n) {
        rep(j,1,n) {
            if(s[i][j]=='S') {
                sx=i; sy=j;
            }
        }
    }
    putchar('D');
    int st=0;
    while(s[sx][sy]!='T') {
        int x,y;
        // printf("\n%d %d %d\n",sx,sy,st);
        if(st==0) {
            if(s[sx][sy+1]=='#') {
                st=1;
                putchar('R');
            }
            else if(s[sx][sy+1]=='T') {
                if(s[sx+1][sy+1]=='#') putchar('D');
                sy=sy+1;
            }
            else {
                if(s[sx+1][sy+1]!='#') {
                    sx=sx+1; sy=sy+1;
                    st=3;
                    putchar('L');
                }
                else {
                    sy=sy+1;
                    putchar('D');
                }
            }
        }
        else if(st==1) {
            if(s[sx-1][sy]=='#') {
                st=2;
                putchar('U');
            }
            else if(s[sx-1][sy]=='T') {
                if(s[sx-1][sy+1]=='#') putchar('R');
                sx=sx-1;
            }
            else {
                if(s[sx-1][sy+1]!='#') {
                    sx=sx-1; sy=sy+1;
                    st=0;
                    putchar('D');
                }
                else {
                    sx=sx-1;
                    putchar('R');
                }
            }
        }
        else if(st==2) {
            if(s[sx][sy-1]=='#') {
                st=3;
                putchar('L');
            }
            else if(s[sx][sy-1]=='T') {
                if(s[sx-1][sy-1]=='#') putchar('U');
                sy=sy-1;
            }
            else {
                if(s[sx-1][sy-1]!='#') {
                    sx=sx-1; sy=sy-1;
                    st=1;
                    putchar('R');
                }
                else {
                    sy=sy-1;
                    putchar('U');
                }
            }
        }
        else {
            if(s[sx+1][sy]=='#') {
                st=0;
                putchar('D');
            }
            else if(s[sx+1][sy]=='T') {
                if(s[sx+1][sy-1]=='#') putchar('L');
                sx=sx+1;
            }
            else {
                if(s[sx+1][sy-1]!='#') {
                    sx=sx+1; sy=sy-1;
                    st=2;
                    putchar('U');
                }
                else {
                    sx=sx+1;
                    putchar('L');
                }
            }
        }
    }
    putchar('\n');
    return 0;
}