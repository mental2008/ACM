#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 100005;
double pre[maxn];
int n;

void init() {
    mem(pre, 0);
    for(int i = 4; i < maxn; ++i) {
        double m = i / 4.0;
        if(i % 4 == 0) pre[i] = i / 2.0 * i / 4.0;
        else if(i % 4 == 1) pre[i] = pre[i - 1] + 1.0 / 2 * m * m - 1.0 / 2 * (m - 1) * (m - 1);
        else if(i % 4 == 2) pre[i] = pre[i - 1] + 1.0 / 2 * m * m - 1.0 / 2 * (m - 1) * (m - 1) + 1;
        else pre[i] = pre[i - 1] + 1.0 / 2 * m * m - 1.0 / 2 * (m - 1) * (m - 1) + 1;
    }
}

int main() {
    init();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        int pos = lower_bound(pre + 4, pre + maxn, (double)n) - pre;
        printf("%d\n", pos);
    }
    return 0;
}
