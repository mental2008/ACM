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
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=305;

int n;
char s[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        scanf("%s",s+1);
        if(n==2&&s[1]>=s[2]) puts("NO");
        else {
            puts("YES\n2");
            printf("%c ",s[1]);
            rep(i,2,n) printf("%c",s[i]);
            puts("");
        }
    }
    return 0;
}

// A