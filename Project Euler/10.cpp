#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e6;
bool vis[maxn];

int main() {
    ll ans=0;
    for(int i=2;i<maxn;++i) {
        if(!vis[i]) {
            ans+=i;
            for(int j=2*i;j<maxn;j+=i) {
                vis[j]=1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}