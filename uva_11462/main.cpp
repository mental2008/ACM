#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        int num[101];
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            num[a]++;
        }
        bool is_first = true;
        for(int i = 1;i <= 100; i++) {
            for(int j = 0; j < num[i]; j++) {
                if(!is_first) {
                    printf(" ");
                }
                is_first = false;
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}