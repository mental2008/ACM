#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
ll n,a,b;

int main() {
    scanf("%lld%lld%lld",&n,&a,&b);
    printf("%lld\n",(n-2)*(b-a)+1);
    return 0;
}