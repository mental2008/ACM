#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int maxn=105;
int cnt[maxn];
int a[maxn];
int n;

int main() {
    scanf("%d",&n);
    mem(cnt,0);
    rep(i,1,n) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int b,c;
    b=c=0;
    rep(i,1,100) {
        if(cnt[i]==1) b++;
        else if(cnt[i]>=3) c++;
    }
    if(b%2==1) {
        if(c==0) {
            puts("NO");
        }
        else {
            puts("YES");
            bool flag=0;
            bool sign=1;
            rep(i,1,n) {
                if(cnt[a[i]]==1) {
                    if(sign) printf("A");
                    else printf("B");
                    sign=!sign;
                }
                else if(cnt[a[i]]==2) printf("A");
                else {
                    if(!flag) printf("B");
                    else printf("A");
                    flag=1;
                }
            }
            puts("");
        }
    }
    else {
        puts("YES");
        bool sign=1;
        rep(i,1,n) {
            if(cnt[a[i]]==1) {
                if(sign) printf("A");
                else printf("B");
                sign=!sign;
            }
            else printf("A");
        }
        puts("");
    }
    return 0;
}
