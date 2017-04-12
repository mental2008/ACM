#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100000
using namespace std;
int x[maxn + 10];
int y[maxn + 10];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, k, q;
        scanf("%d%d%d%d", &n, &m, &k, &q);
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for(int i = 1; i <= k; i++) {
            int x0, y0;
            scanf("%d%d", &x0, &y0);
            x[x0] = 1;
            y[y0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            x[i] += x[i - 1];
        }
        for(int i = 1; i <= m; i++) {
            y[i] += y[i - 1];
        }

//        cout << endl;
//        for(int i = 1; i <= n; i++) {
//            cout << x[i] << endl;
//        }
//        cout << endl;
//
//        cout << endl;
//        for(int i = 1; i <= m; i++) {
//            cout << y[i] << endl;
//        }
//        cout << endl;

        for(int i = 1; i <= q; i++) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//            cout << x2 - x1 + 1 << endl;
//            cout << x[x2] << " " << x[x1 - 1] << endl;
//            cout << y1 - y2 + 1 << endl;
//            cout << y[y1] << " " << y[y2 - 1] << endl;
            if((x[x2] - x[x1 - 1] == x2 - x1 + 1) || (y[y2] - y[y1 - 1] == y2 - y1 + 1)) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }
    return 0;
}