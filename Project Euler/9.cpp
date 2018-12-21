#include<bits/stdc++.h>

using namespace std;

int main() {
    for(int i=1;i<=1000;++i) {
        for(int j=i+1;j<=1000;++j) {
            int k=1000-i-j;
            if(j>=k) break;
            if(k*k==i*i+j*j) {
                printf("%d\n",i*j*k);
            }
        }
    }
    return 0;
}