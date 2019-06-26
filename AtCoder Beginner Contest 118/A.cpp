#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

int main() {
    int a,b;
    while(~scanf("%d%d",&a,&b)) {
        if(b%a==0) printf("%d\n",a+b);
        else printf("%d\n",b-a);
    }
    return 0;
}