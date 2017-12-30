#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    string s;
    while(cin >> s) {
        int len = s.size();
        int ans = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ans++;
            }
            else if(s[i] >= '0' && s[i] <= '9' && ((s[i] - '0') % 2 == 1)) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
