#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 105;
int n;
char s[maxn];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", s);
        int cnt = 0;
        int r = 0, d = 0, u = 0, l = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'R') r++;
            else if(s[i] == 'D') d++;
            else if(s[i] == 'U') u++;
            else l++;
        }
        cnt = 2 * min(l, r) + 2 * min(u, d);
        printf("%d\n", cnt);
    }
    return 0;
}
