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

const int maxn=1e5+5;
char s[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%s",s);
        int len=strlen(s);
        if(len%4==0) {
            bool ok=true;
            for(int i=0;i<len;i+=4) {
                if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='5'&&s[i+3]=='0') {
                    ;
                }
                else {
                    ok=false;
                    break;
                }
            }
            if(ok) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
    return 0;
}