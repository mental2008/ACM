#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string s;
    while(cin >> s) {
        int L = s.size();
        int q;
        cin >> q;
        while(q--) {
            int l, r;
            string z;
            cin >> l >> r >> z;
            int len = z.size();
            int ans = 0;
            for(int i = l; i + len - 1 <= r; ++i) {
                if(s.substr(i, len) == z) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
