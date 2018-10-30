#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node {
    int index;
    int val;
    bool operator < (const Node& e) const {
        return val < e.val;
    }
} node[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        node[a].index = a;
        node[a].val = i;
    }
    int MIN = 0;
    int MAX = n + 1;
    int p;
    scanf("%d", &p);
    while(p--) {
        char order[10];
        scanf("%s", order);
        int a;
        scanf("%d", &a);
        if(order[0] == 'F') {
            node[a].val = MIN--;
        }
        else {
            node[a].val = MAX++;
        }
    }
    sort(node + 1, node + 1 + n);
    for(int i = 1; i <= n; ++i) {
        printf("%d%c", node[i].index, (i == n ? '\n' : ' '));
    }
    return 0;
}
