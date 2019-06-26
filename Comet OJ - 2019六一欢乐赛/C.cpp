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

const int maxn=1e6+5;
char s[maxn];
char t[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1);
        int m=strlen(t+1);
        if(n==m+2) {
            int j=1;
            bool ok=true;
            rep(i,1,m) {
                while(j<=n) {
                    if(s[j]==t[i]) break;
                    j++;
                }
                if(j>n) {
                    ok=false;
                    break;
                }
                j++;
            }
            if(ok) puts("1");
            else puts("0");
        }
        else puts("0");
    }
    return 0;
}