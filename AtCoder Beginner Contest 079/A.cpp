#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[10];
    scanf("%s", s);
    if((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])) puts("Yes");
    else puts("No");
    return 0;
}
