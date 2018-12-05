#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef double db;

const int maxn=2005;
int a[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d",&a[i]);
    }
    printf("%d\n",n+1);
    per(i,n,1) {
        int p=a[i]%n;
        p=n+i-1-p;
        printf("1 %d %d\n",i,p);
        rep(j,1,i) {
            a[j]+=p;
        }
    }
    printf("2 %d %d\n",n,n);
    return 0;
}