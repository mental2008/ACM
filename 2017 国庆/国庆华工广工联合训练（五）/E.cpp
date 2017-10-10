#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 55;
char ch[maxn][maxn];
int sign[maxn][maxn];
int n, m;
int p[4] = {0, 0, 1, -1};
int q[4] = {1, -1, 0, 0};
int hagi[2][2];
int button[105][2];
bool vis[105][105][105];
struct Node {
    int x, y;
    int r1, c1;
    int r2, c2;
    int step;
    Node(int _x, int _y, int _r1, int _c1, int _r2, int _c2, int _step) {
        x = _x, y = _y;
        r1 = _r1, c1 = _c1;
        r2 = _r2, c2 = _c2;
        step = _step;
    }
};
queue<Node> Q;
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%s", ch[i]);
        }
        int sx, sy;
        int ex, ey;
        int buttonNum = 0;
        int hagiNum = 0;
        mem(vis, 0);
        mem(sign, 0);
        int cnt = 0;
        sign[52][52] = 101;
        hagi[0][0] = hagi[0][1] = hagi[1][0] = hagi[1][1] = 52;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(ch[i][j] != '#') sign[i][j] = ++cnt;
                if(ch[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if(ch[i][j] == 'E') {
                    ex = i;
                    ey = j;
                }
                else if(ch[i][j] == 'B') {
                    button[buttonNum][0] = i;
                    button[buttonNum][1] = j;
                    buttonNum++;
                }
                else if(ch[i][j] == 'X') {
                    hagi[hagiNum][0] = i;
                    hagi[hagiNum][1] = j;
                    hagiNum++;
                }
            }
        }
        if(buttonNum > hagiNum) {
            puts("impossible");
            continue;
        }
        while(!Q.empty()) Q.pop();
        Node node0(sx, sy, hagi[0][0], hagi[0][1], hagi[1][0], hagi[1][1], 0);
        Q.push(node0);
        vis[sign[sx][sy]][sign[hagi[0][0]][hagi[0][1]]][sign[hagi[1][0]][hagi[1][1]]] = 1;
        bool ok = false;
        while(!Q.empty()) {
            Node node = Q.front();
            Q.pop();
            if(node.x == ex && node.y == ey) {
                if(hagiNum == 2) {
                    if(buttonNum == 2) {
                        if((node.r1 == button[0][0] && node.c1 == button[0][1] &&
                        node.r2 == button[1][0] && node.c2 == button[1][1]) ||
                        (node.r1 == button[1][0] && node.c1 == button[1][1] &&
                        node.r2 == button[0][0] && node.c2 == button[0][1])) {
                            ok = true;
                            printf("%d\n", node.step);
                            break;
                        }
                    }
                    else if(buttonNum == 1) {
                        if((node.r1 == button[0][0] && node.c1 == button[0][1]) ||
                        (node.r2 == button[0][0] && node.c2 == button[0][1])) {
                            ok = true;
                            printf("%d\n", node.step);
                            break;
                        }
                    }
                    else {
                        ok = true;
                        printf("%d\n", node.step);
                        break;
                    }
                }
                else if(hagiNum == 1) {
                    if(buttonNum == 1) {
                        if((node.r1 == button[0][0] && node.c1 == button[0][1]) ||
                        (node.r2 == button[0][0] && node.c2 == button[0][1])) {
                            ok = true;
                            printf("%d\n", node.step);
                            break;
                        }
                    }
                    else {
                        ok = true;
                        printf("%d\n", node.step);
                        break;
                    }
                }
                else {
                    ok = true;
                    printf("%d\n", node.step);
                    break;
                }
            }
            for(int i = 0; i < 4; ++i) {
                int xx = node.x + p[i];
                int yy = node.y + q[i];
                int rr1 = node.r1;
                int cc1 = node.c1;
                int rr2 = node.r2;
                int cc2 = node.c2;
                if(xx < 0 || xx >= n || yy < 0 || yy >= m || ch[xx][yy] == '#') continue;
                if(xx == rr1 && yy == cc1) {
                    if(rr1 + p[i] < 0 || rr1 + p[i] >= n || cc1 + q[i] < 0 ||
                    cc1 + q[i] >= m || ch[rr1 + p[i]][cc1 + q[i]] == '#') continue;
                    rr1 += p[i];
                    cc1 += q[i];
                    if(rr1 == rr2 && cc1 == cc2) continue;
                }
                if(xx == rr2 && yy == cc2) {
                    if(rr2 + p[i] < 0 || rr2 + p[i] >= n || cc2 + q[i] < 0 ||
                    cc2 + q[i] >= m || ch[rr2 + p[i]][cc2 + q[i]] == '#') continue;
                    rr2 += p[i];
                    cc2 += q[i];
                    if(rr1 == rr2 && cc1 == cc2) continue;
                }
                if(vis[sign[xx][yy]][sign[rr1][cc1]][sign[rr2][cc2]]) continue;
                vis[sign[xx][yy]][sign[rr1][cc1]][sign[rr2][cc2]] = 1;
                // printf("%d %d %d %d %d %d %d\n", xx, yy, rr1, cc1, rr2, cc2, node.step + 1);
                Q.push((Node){xx, yy, rr1, cc1, rr2, cc2, node.step + 1});
            }
        }
        if(!ok) puts("impossible");
    }
    return 0;
}
