#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
vector<int> ans;
const int maxn = 125255;
int a[maxn];
int n, m;
map<int, int> mp;
map<int, int> vis;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d", &m)) {
        n = (-1 + sqrt(1 + 8 * m)) / 2;
        vis.clear();
        mp.clear();
        ans.clear();
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &a[i]);
            mp[a[i]]++;
        }
        sort(a + 1, a + 1 + m);
        for(int i = 1; i <= m; ++i) {
            if(vis[a[i]] < mp[a[i]]) {
                vis[a[i]]++;
                for(int j = 0; j < (int)ans.size(); ++j) {
                    vis[a[i] + ans[j]]++;
                }
                ans.push_back(a[i]);
            }
        }
        int len = (int)ans.size();
        sort(ans.begin(), ans.end());
        printf("%d\n", len);
        for(int i = 0; i < len; ++i) {
            printf("%d", ans[i]);
            printf("%c", (i == len - 1 ? '\n' : ' '));
        }
    }
    return 0;
}
