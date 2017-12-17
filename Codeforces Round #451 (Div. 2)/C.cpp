#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
map<string, int> mp;
string s[25];
int cnt;
struct Node {
    map<string, int> vec;
} node[25];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        for(int i = 1; i <= 20; ++i) node[i].vec.clear();
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            string name;
            int m;
            cin >> name >> m;
            if(mp[name] == 0) {
                mp[name] = ++cnt;
                s[cnt] = name;
            }
            int index = mp[name];
            while(m--) {
                string k;
                cin >> k;
                node[index].vec[k] = 1;
            }
        }
        for(int i = 1; i <= cnt; ++i) {
            for(auto &x : node[i].vec) {
                if(x.second) {
                    string k = x.first;
                    int len = k.size();
                    for(int j = 1; j < len; ++j) {
                        string temp = k.substr(j, len - j);
                        // cout << temp << '\n';
                        node[i].vec[temp] = 0;
                    }
                }
            }
        }
        cout << cnt << '\n';
        for(int i = 1; i <= cnt; ++i) {
            cout << s[i];
            int number = 0;
            for(auto &x : node[i].vec) {
                if(x.second) {
                    number++;
                }
            }
            cout << " " << number;
            for(auto &x : node[i].vec) {
                if(x.second) {
                    cout << " " << x.first;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
