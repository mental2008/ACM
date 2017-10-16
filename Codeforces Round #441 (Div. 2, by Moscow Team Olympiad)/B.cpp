#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, k, m;
struct Node {
    int a;
    int val;
} node[maxn];
bool cmp(Node x, Node y) {
    return x.val < y.val;
}
int main() {
    while(~scanf("%d%d%d", &n, &k, &m)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &node[i].a);
            node[i].val = node[i].a % m;
        }
        sort(node + 1, node + 1 + n, cmp);
        bool ok = false;
        for(int i = 1; i <= n;) {
            int l = i, r = n;
            int temp = i;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(node[i].val < node[mid].val) {
                    r = mid - 1;
                }
                else if (node[i].val > node[mid].val) {
                    l = mid + 1;
                }
                else {
                    temp = mid;
                    l = mid + 1;
                }
            }
            if(temp - i + 1 >= k) {
                ok = true;
                puts("Yes");
                for(int j = 0; j < k; ++j) {
                    printf("%d ", node[j + i].a);
                }
                puts("");
                break;
            }
            i = temp + 1;
        }
        if(!ok) puts("No");
    }
    return 0;
}
