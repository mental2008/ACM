#include <bits/stdc++.h>
using namespace std;
int n, k;
char ch[6][105];

int main()
{
    scanf("%d%d", &n, &k);
    if(k % 2 == 0) {
        puts("YES");
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < n; ++j) {
                ch[i][j] = '.';
            }
        }
        for(int i = 1; i <= (k / 2); ++i) {
            ch[1][i] = ch[2][i] = '#';
        }
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < n; ++j) {
                printf("%c", ch[i][j]);
            }
            puts("");
        }
    }
    else {
        if(k == 2 * (n - 2) - 1) {
            puts("YES");
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < n; ++j) {
                    ch[i][j] = '.';
                }
            }
            for(int i = 1; i < 3; ++i) {
                for(int j = 1; j < n - 1; ++j) {
                    ch[i][j] = '#';
                }
            }
            ch[2][n / 2] = '.';
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < n; ++j) {
                    printf("%c", ch[i][j]);
                }
                puts("");
            }
        }
        else {
            puts("YES");
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < n; ++j) {
                    ch[i][j] = '.';
                }
            }
            ch[1][n / 2] = '#';
            int cnt = 1;
            int pos1 = 1;
            int pos2 = n - 2;
            while(1) {
                if(cnt == k) break;
                ch[1][pos1] = '#';
                cnt++;
                if(cnt == k) break;
                ch[1][pos2] = '#';
                cnt++;
                if(cnt == k) break;
                ch[2][pos1] = '#';
                cnt++;
                pos1++;
                if(cnt == k) break;
                ch[2][pos2] = '#';
                cnt++;
                pos2--;
            }
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < n; ++j) {
                    printf("%c", ch[i][j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
