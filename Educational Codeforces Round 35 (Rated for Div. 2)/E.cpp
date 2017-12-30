#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int a[maxn];
bool vis[maxn];
int n, k;
stack<int> s;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d%d", &n, &k)) {
        mem(vis, 0);
        for(int i = 1; i <= k; ++i) {
            scanf("%d", &a[i]);
            vis[a[i]] = 1;
        }
        while(!s.empty()) s.pop();
        int x = 0;
        bool ok = true;
        for(int i = 1; i <= k; ++i) {
            if(a[i] != (x + 1)) {
                if((!s.empty()) && s.top() < a[i]) {
                    ok = false;
                    break;
                }
                s.push(a[i]);
            }
            else {
                x++;
                while(!s.empty() && s.top() == (x + 1)) {
                    x++;
                    s.pop();
                }
            }
        }
        if(!ok) {
            puts("-1");
            continue;
        }
        for(int i = k + 1; i <= n; ++i) {
            a[i] = -1;
            for(int j = (s.empty() ? n : (s.top() - 1)); j > x; --j) {
                if(!vis[j]) {
                    vis[j] = 1;
                    a[i] = j;
                    s.push(j);
                    break;
                }
            }
            if(a[i] == -1) {
                ok = false;
                break;
            }
            while((!s.empty()) && s.top() == (x + 1)) {
                x++;
                s.pop();
            }
        }
        if(!ok) {
            puts("-1");
            continue;
        }
        for(int i = 1; i <= n; ++i) {
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}
