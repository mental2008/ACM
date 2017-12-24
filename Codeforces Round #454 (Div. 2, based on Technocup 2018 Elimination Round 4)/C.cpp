#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int vis[30];
    mem(vis, 0);
    bool check = false;
    char res;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        char action;
        string s;
        cin >> action >> s;
        int len = s.size();
        if(check) {
            if(action == '!') ans++;
            else if(action == '?') {
                if(s[0] != res) ans++;
            }
            continue;
        }
        if(action == '!') {
            for(int j = 0; j < 26; ++j) {
                if(vis[j] == 0) {
                    bool fuck = false;
                    for(int k = 0; k < len; ++k) {
                        if(s[k] - 'a' == j) {
                            fuck = true;
                            break;
                        }
                    }
                    if(fuck) vis[j] = 1;
                    else vis[j] = -1;
                }
                else if(vis[j] == 1) {
                    bool fuck = false;
                    for(int k = 0; k < len; ++k) {
                        if(s[k] - 'a' == j) {
                            fuck = true;
                            break;
                        }
                    }
                    if(!fuck) vis[j] = -1;
                }
            }
        }
        else if(action == '.') {
            for(int j = 0; j < len; ++j) {
                if(vis[s[j] - 'a'] == 1 || vis[s[j] - 'a'] == 0) {
                    vis[s[j] - 'a'] = -1;
                }
            }
        }
        else {
            vis[s[0] - 'a'] = -1;
        }
        int ok = 0;
        for(int j = 0; j < 26; ++j) {
            if(vis[j] == 1 || vis[j] == 0) {
                ok++;
                res = j + 'a';
            }
        }
        // for(int i = 0; i < 26; ++i) {
        //     if(vis[i] == 1) cout << (char)(i + 'a') << ' ';
        // }
        // cout << '\n';
        if(ok == 1) check = true;
    }
    cout << ans << '\n';
    return 0;
}
