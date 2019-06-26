#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
int n, m, k;
char s[maxn][12];
map<int, int> mp;

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    rep(T, 1, caseCnt) {
        scanf("%d%d%d", &n, &m, &k);
        rep(i, 0, n - 1) scanf("%s", s[i]);
        int ans = 0;
        rep(i, 1, (1 << m) - 1) {
            mp.clear();
            rep(j, 0, n - 1) {
                int res = 0;
                rep(k, 0, m - 1) {
                    if((i >> k) & 1) {
                        res += ((s[j][k] - 'A') << k);
                    }
                }
                mp[res]++;
            }
            int res = n * (n - 1) / 2;
            for(auto x : mp) {
                res -= (x.second * (x.second - 1) / 2);
            }
            if(res >= k) {
                ans++;
            }
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
