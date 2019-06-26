#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
typedef long long LL;
bool vis[maxn];
vector<int> prime;

int main()
{
    memset(vis, 0, sizeof(vis));
    prime.clear();
    for(int i = 2; i < maxn; ++i) {
        if(vis[i] == 0) {
            prime.push_back(i);
            for(int j = i * 2; j < maxn; j += i) {
                vis[j] = 1;
            }
        }
    }
    int len = (int)prime.size();
    int n;
    while(~scanf("%d", &n)) {
        LL ans = 0;
        for(int i = 0; i < len; ++i) {
            if(prime[i] > n) break;
            ans += (1LL * i * (n / prime[i]));
        }
        ans *= 2LL;
        printf("%lld\n", ans);
    }
    return 0;
}
