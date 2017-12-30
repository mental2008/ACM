#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 55;
int n, m;
char ch[maxn][maxn];
char instruction[105];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", ch[i]);
        }
        scanf("%s", instruction);
        int len = strlen(instruction);
        int x, y;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(ch[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(j == i) continue;
                for(int k = 0; k < 4; ++k) {
                    if(k == j || k == i) continue;
                    for(int l = 0; l < 4; ++l) {
                        if(l == k || l == j || l == i) continue;
                        int xx = x, yy = y;
                        bool ok = false;
                        for(int p = 0; p < len; ++p) {
                            int temp = instruction[p] - '0';
                            if(temp == i) yy -= 1;
                            else if(temp == j) yy += 1;
                            else if(temp == k) xx -= 1;
                            else if(temp == l) xx += 1;
                            if(xx < 0 || xx >= n || yy < 0 || yy >= m || ch[xx][yy] == '#') {
                                break;
                            }
                            else if(ch[xx][yy] == 'E') {
                                ok = true;
                                break;
                            }
                        }
                        if(ok) {
                            ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
