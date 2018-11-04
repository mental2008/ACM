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
bool cnt[4][13];
char s[5];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        mem(cnt,0);
        rep(i,1,51) {
            scanf("%s",s);
            int len=strlen(s);
            if(len==3) {
                cnt[s[0]-'A'][9]=1;
            }
            else {
                if(s[1]=='J') cnt[s[0]-'A'][10]=1;
                else if(s[1]=='Q') cnt[s[0]-'A'][11]=1;
                else if(s[1]=='K') cnt[s[0]-'A'][12]=1;
                else cnt[s[0]-'A'][s[1]-'1']=1;
            }
        }
        bool ok=false;
        rep(i,0,3) {
            rep(j,0,12) {
                if(cnt[i][j]==0) {
                    ok=true;
                    printf("%c",('A'+i));
                    if(j==10) puts("J");
                    else if(j==11) puts("Q");
                    else if(j==12) puts("K");
                    else printf("%d\n",j+1);
                }
                if(ok) break;
            }
            if(ok) break;
        }
    }
    return 0;
}