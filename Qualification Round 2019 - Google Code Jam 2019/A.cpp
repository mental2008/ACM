#include <bits/stdc++.h>

using namespace std;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    int T=0;
    while(caseCnt--) {
        int n;
        scanf("%d",&n);
        int a=0;
        int b=0;
        int p=1;
        while(n) {
            if(n%10==4) {
                a+=2*p;
                b+=2*p;
            }
            else {
                a+=(n%10)*p;
            }
            n/=10;
            p*=10;
        }
        printf("Case #%d: %d %d\n",++T,a,b);
    }
    return 0;
}