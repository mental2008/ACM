#include <bits/stdc++.h>

using namespace std;
string s;

bool judge() {
    int len = (int)s.size();
    bool zero = false;
    bool number = false;
    bool op = false;
    for(int i = 0; i < len; ++i) {
        if(s[i] >= '1' && s[i] <= '9') {
            if(zero) return false;
            number = true;
            op = false;
            continue;
        }
        if(s[i] == '0') {
            if(zero) return false;
            if(!number) zero = true;
            op = false;
            continue;
        }
        if(s[i] == '+' || s[i] == '*') {
            if(op) return false;
            if(i == len - 1 || i == 0) return false;
            op = true;
            number = false;
            zero = false;
        }
        if(s[i] == '?') {
            if(zero) {
                s[i] = '+';
                op = true;
                number = false;
                zero = false;
                if(i == len - 1 || i == 0) return false;
            }
            else {
                s[i] = '1';
                op = false;
                zero = false;
                number = true;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int caseCnt;
    cin >> caseCnt;
    while(caseCnt--) {
        cin >> s;
        if(judge()) {
            cout << s << '\n';
        }
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
