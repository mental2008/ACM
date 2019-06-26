#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
    cin >> s;
    int len = (int)s.size();
    int x = 0, y = 0;
    for(int i = 0; i < len; ++i) {
        if(s[i] == '-') x++;
        else if(s[i] == 'o') y++;
    }
    if(y == 0) cout << "YES\n";
    else if(x % y == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
