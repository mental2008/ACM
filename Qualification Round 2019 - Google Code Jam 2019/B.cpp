#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+5;
char s[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    int T=0;
    while(caseCnt--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        printf("Case #%d: ",++T);
        if(s[1]=='S'&&s[2*(n-1)]=='E') {
            for(int i=1;i<=n-1;++i) putchar('E');
            for(int i=1;i<=n-1;++i) putchar('S');
            puts("");
        }
        else if(s[1]=='E'&&s[2*(n-1)]=='S') {
            for(int i=1;i<=n-1;++i) putchar('S');
            for(int i=1;i<=n-1;++i) putchar('E');
            puts("");
        }
        else if(s[1]=='S'&&s[2*(n-1)]=='S') {
            int cnt=0;
            for(int i=2;i<2*(n-1);++i) {
                if(s[i]=='E') cnt++;
                if(s[i-1]=='S'&&s[i]=='E'&&s[i+1]=='E') {
                    break;
                }
            }
            for(int i=1;i<=cnt;++i) putchar('E');
            for(int i=1;i<=n-1;++i) putchar('S');
            for(int i=cnt+1;i<=n-1;++i) putchar('E');
            puts("");
        }
        else {
            int cnt=0;
            for(int i=2;i<2*(n-1);++i) {
                if(s[i]=='S') cnt++;
                if(s[i-1]=='E'&&s[i]=='S'&&s[i+1]=='S') {
                    break;
                }
            }
            for(int i=1;i<=cnt;++i) putchar('S');
            for(int i=1;i<=n-1;++i) putchar('E');
            for(int i=cnt+1;i<=n-1;++i) putchar('S');
            puts("");
        }
    }
    return 0;
}