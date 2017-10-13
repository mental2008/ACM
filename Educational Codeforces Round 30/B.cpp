#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 100005;
int n;
char s[maxn];
int one[maxn];
int zero[maxn];
struct Node {
    int val;
    int index;
} node[maxn];
bool cmp(Node x, Node y) {
    if(x.val == y.val) return x.index < y.index;
    else return x.val < y.val;
}
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    mem(one, 0);
    mem(zero, 0);
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '1') {
            one[i] = one[i - 1] + 1;
            zero[i] = zero[i - 1];
        }
        else {
            one[i] = one[i - 1];
            zero[i] = zero[i - 1] + 1;
        }
    }
    for(int i = 0; i <= n; ++i) {
        node[i].val = one[i] - zero[i];
        node[i].index = i;
    }
    sort(node, node + 1 + n, cmp);
    int ans = 0;
    for(int i = 0; i <= n;) {
        int l = i, r = n;
        int j = i;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(node[mid].val > node[i].val) r = mid - 1;
            else if(node[mid].val < node[i].val) l = mid + 1;
            else if(node[mid].index > node[j].index) j = mid, l = mid + 1;
            else l = mid + 1;
        }
        ans = max(ans, node[j].index - node[i].index);
        i = j + 1;
    }
    printf("%d\n", ans);
    return 0;
}
