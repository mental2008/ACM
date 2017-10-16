#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const int maxNum = (1 << 20) + 5;
char s[25];
bool vis[maxNum];
int n, k;
struct Node {
    int val;
    int step;
    Node(int _val, int _step) {
        val = _val, step = _step;
    }
};
queue<Node> q;
int main() {
    while(~scanf("%d%d", &n, &k)) {
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            int res = 0;
            for(int j = 0; j < k; ++j) {
                res += ((s[j] - '0') << (k - j - 1));
            }
            if(!vis[res]) {
                Node node(res, 0);
                q.push(node);
                vis[res] = 1;
            }
        }
        int ans = q.front().val;
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            // printf("%d %d\n", node.val, node.step);
            ans = node.val;
            for(int i = 0; i < k; ++i) {
                int res = (1 << (k - i - 1)) ^ node.val;
                if(!vis[res]) {
                    Node temp(res, node.step + 1);
                    q.push(temp);
                    vis[res] = 1;
                }
            }
        }
        for(int i = k - 1; i >= 0; --i) {
            printf("%d", (ans >> i) & 1);
        }
        puts("");
    }
    return 0;
}
