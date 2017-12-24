#include <bits/stdc++.h>
using namespace std;
char ch[15][15];
int main() {
    ios::sync_with_stdio(false);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> ch[i][j];
        }
    }
    int n, m;
    cin >> n >> m;
    n--;
    m--;
    int index = 3 * (n / 3) + (m / 3);
    n = n % 3;
    m = m % 3;
    bool ok = false;
    for(int i = 3 * n; i < 3 * n + 3; ++i) {
        for(int j = 3 * m; j < 3 * m + 3; ++j) {
            if(ch[i][j] == '.') {
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) {
        for(int i = 3 * n; i < 3 * n + 3; ++i) {
            for(int j = 3 * m; j < 3 * m + 3; ++j) {
                if(ch[i][j] == '.') {
                    ch[i][j] = '!';
                }
            }
        }
    }
    else {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(ch[i][j] == '.') ch[i][j] = '!';
            }
        }
    }
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << ch[i][j];
            if(j == 2 || j == 5) cout << ' ';
        }
        cout << '\n';
        if(i % 3 == 2) cout << '\n';
    }
    return 0;
}
