#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

struct Node {
    int l, r;
} node[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &node[i].l, &node[i].r);
    }
    int res = 0;
    for(int i = 0; i < m; ++i) {
        int sum = node[i].r - node[i].l + 1;
        if(sum % 2 == 0) {
            res += (sum / 2) * (sum / 2);
        }
        else {
            res += (sum / 2 + 1) * (sum / 2);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}
