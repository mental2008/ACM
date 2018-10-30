#include <bits/stdc++.h>
using namespace std;
char ch[5][105];

int main()
{
    for(int i = 0; i < 2; ++i) {
        scanf("%s", ch[i]);
    }
    int len = strlen(ch[0]);
    int ans = 0;
    for(int i = 0; i < len - 1; ++i) {
        if(ch[0][i] == '0' && ch[1][i] == '0' && ch[0][i + 1] == '0') {
            ch[0][i] = 'X';
            ch[1][i] = 'X';
            ch[0][i + 1] = 'X';
            ans++;
        }
        if(ch[0][i] == '0' && ch[1][i] == '0' && ch[1][i + 1] == '0') {
            ch[0][i] = 'X';
            ch[1][i] = 'X';
            ch[1][i + 1] = 'X';
            ans++;
        }
        if(ch[0][i] == '0' && ch[1][i + 1] == '0' && ch[0][i + 1] == '0') {
            ch[0][i] = 'X';
            ch[1][i + 1] = 'X';
            ch[0][i + 1] = 'X';
            ans++;
        }
        if(ch[1][i] == '0' && ch[1][i + 1] == '0' && ch[0][i + 1] == '0') {
            ch[1][i] = 'X';
            ch[1][i + 1] = 'X';
            ch[0][i + 1] = 'X';
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
