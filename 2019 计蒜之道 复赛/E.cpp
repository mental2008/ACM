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

const int maxn=1e6+5;
char s[maxn];
char t[maxn];
int sum[maxn];

int main() {
    scanf("%s",s+1);
    int n=strlen(s+1);
    strcpy(t+1,s+1);
    sum[0]=0;
    rep(i,1,n) {
        sum[i]=sum[i-1]+(s[i]=='('?1:-1);
    }
    per(i,n,2) {
        if(t[i]=='('&&t[i-1]==')') {
            swap(t[i],t[i-1]);
            rep(j,1,i) printf("%c",t[j]);
            rep(j,1,sum[i-2]) printf(")");
            rep(j,1,(n-i-sum[i-2])/2) {
                printf("()");
            }
            puts("");
            // printf("%s\n",t+1);
            break;
        }
    } // qianqu
    per(i,n,2) {
        if(s[i]==')'&&s[i-1]=='('&&sum[i-2]>0) {
            swap(s[i],s[i-1]);
            sort(s+i,s+n+1);
            printf("%s\n",s+1);
            break;
        }
    } // houji
    return 0;
}