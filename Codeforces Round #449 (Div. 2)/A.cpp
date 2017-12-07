#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
int main() {
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= m; ++i) {
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for(int j = l - 1; j <= r - 1; ++j) {
            if(s[j] == c1) s[j] = c2;
        }
    }
    cout << s << '\n';
    return 0;
}
