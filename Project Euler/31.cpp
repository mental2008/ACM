#include<bits/stdc++.h>

using namespace std;

int dp[205];
int a[8]={1,2,5,10,20,50,100,200};

int main() {
    dp[0]=1;
    for(int j=0;j<8;++j) {
        for(int i=1;i<=200;++i) {
            if(i>=a[j]) {
                dp[i]+=dp[i-a[j]];
            }
        }
    }
    printf("%d\n",dp[200]);
    return 0;
}