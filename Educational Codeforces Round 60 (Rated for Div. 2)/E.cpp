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
typedef vector<int> vi;

const int maxn=1e4+5;
char t[maxn];
int n;
char ch[30]="abcdefghijklmnopqrstuvwxyz";
char s[3][maxn];
char ans[3][maxn];
char old[maxn];
int len[3];

int main() {
    scanf("%s",t);
    n=strlen(t);
    len[0]=23;
    len[1]=25;
    len[2]=26;
    rep(i,0,2) {
        rep(j,0,n-1) {
            s[i][j]=ch[j%len[i]];
        }
        s[i][n]='\0';
        printf("? %s\n",s[i]);
        fflush(stdout);
        scanf("%s",ans[i]);
    }
    rep(j,0,n-1) {
        rep(k,0,n-1) {
            bool ok=true;
            rep(i,0,2) {
                if(k%len[i]!=ans[i][j]-'a') {
                    ok=false;
                    break;
                }
            }
            if(ok) {
                old[k]=t[j];
            }
        }
    }
    old[n]='\0';
    printf("! %s\n",old);
    return 0;
}