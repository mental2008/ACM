#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[10];
    scanf("%s", s);
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                int temp = a;
                if(i == 0) temp -= b;
                else temp += b;
                if(j == 0) temp -= c;
                else temp += c;
                if(k == 0) temp -= d;
                else temp += d;
                if(temp == 7) {
                    printf("%d%c%d%c%d%c%d=7\n", a, (i == 0 ? '-' : '+'), b, (j == 0 ? '-' : '+'), c, (k == 0 ? '-' : '+'), d);
                    return 0;
                }
            }
        }
    }
}
