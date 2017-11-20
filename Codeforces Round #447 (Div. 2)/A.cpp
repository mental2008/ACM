#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    for(int i = 0; i < len; ++i) {
        if(s[i] == 'Q') {
            for(int j = i + 1; j < len; ++j) {
                if(s[j] == 'A') {
                    for(int k = j + 1; k < len; ++k) {
                        if(s[k] == 'Q') {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
