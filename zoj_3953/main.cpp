#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define maxn 50000
#define exps 1e-5
using namespace std;

struct Segment {
    int l, r;
    int sign;
}node[maxn + 10];

vector<int> ans;

bool cmpl(Segment x, Segment y) {
    return x.l < y.l;
}

bool intersect(Segment x, Segment y) {
    if(x.r < y.l || x.l > y.r) return false;
    return true;
}

bool cmpr(Segment x, Segment y) {
    if(x.r == y.r) return x.l < y.l;
    return x.r > y.r;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        ans.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &node[i].l, &node[i].r);
            node[i].sign = i;
        }
        sort(node + 1, node + 1 + n, cmpl);
        Segment tmp[3];
        tmp[0] = node[1], tmp[1] = node[2];
        for(int i = 3; i <= n; i++) {
            tmp[2] = node[i];
            sort(tmp, tmp + 3, cmpr);
            if(intersect(tmp[0], tmp[1]) && intersect(tmp[0], tmp[2]) && intersect(tmp[1], tmp[2])) {
                ans.push_back(tmp[0].sign);
                tmp[0] = tmp[2];
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", (int)ans.size());
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}