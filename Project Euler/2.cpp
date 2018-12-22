#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=4000000;
int f[maxn];

int main() {
    ll ans=0;
    f[1]=1;f[2]=2;
    for(int i=3;;++i) {
        f[i]=f[i-1]+f[i-2];
        if(f[i]>maxn*100) break;
        if(f[i]%2==0&&f[i]<=maxn) ans+=f[i];
    }
    printf("%lld\n",ans+2);
    return 0;
}