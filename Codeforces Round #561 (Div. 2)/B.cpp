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

const int maxn=2005;
int k;
char vowel[5]={'a','e','i','o','u'};
int n,m,x,y;
char ch[maxn][maxn];

void solve() {
    rep(p,1,n) {
        rep(q,1,m) {
            int startx=5*p-4,starty=5*q-4;
            rep(i,0,4) {
                rep(j,0,4) {
                    ch[startx+i][starty+j]=vowel[(i+j)%5];
                }
            }
        }
    }
    rep(q,1,y) {
        rep(p,1,5*n) {
            ch[p][q+5*m]=vowel[(p-1)%5];
        }
    }
    rep(p,1,x) {
        rep(q,1,5*m+y) {
            ch[p+5*n][q]=vowel[(q-1)%5];
        }
    }
    rep(i,1,5*n+x) {
        rep(j,1,5*m+y) putchar(ch[i][j]);
        // puts("");
    }
    puts("");
}

int main() {
    scanf("%d",&k);
    rep(i,1,k) {
        if(k%i==0) {
            int j=k/i;
            if(i>=5&&j>=5) {
                n=i/5,x=i%5;
                m=j/5,y=j%5;
                solve();
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}