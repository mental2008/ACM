#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;
char s[maxn];
int sign[30];
int res[30];

int main() {
    while(~scanf("%s", s)) {
        mem(sign, -1);
        mem(res, 0);
        int len = strlen(s);
        for(int i = 0; i < len; ++i) {
            int x = s[i] - 'a';
            res[x] = max(i - sign[x], res[x]);
            sign[x] = i;
        }
        int ans = INF;
        for(int i = 0; i < 26; ++i) {
            res[i] = max(len - sign[i], res[i]);
            ans = min(res[i], ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
