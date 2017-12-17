#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-6;
const int maxn = 1e5 + 5;
int n;
vector<int> vec;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        vec.clear();
        int i;
        for(i = n; i >= 1; i -= 4) {
            if(i < 4) break;
            vec.push_back(i);
            vec.push_back(i - 3);
        }
        i = (i + 4) % 4;
        int ans = 0;
        if(i == 1) {
            vec.push_back(1);
            ans = 1;
        }
        else if(i == 2) {
            vec.push_back(1);
            ans = 1;
        }
        else if(i == 3) {
            vec.push_back(1);
            vec.push_back(2);
        }
        printf("%d\n", ans);
        int len = vec.size();
        printf("%d", len);
        for(int i = 0; i < len; ++i) {
            printf(" %d", vec[i]);
        }
        puts("");
    }
    return 0;
}
