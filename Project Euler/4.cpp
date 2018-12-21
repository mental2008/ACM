#include<bits/stdc++.h>

using namespace std;

bool judge(int x) {
    int temp[10];
    int cnt=0;
    while(x) {
        temp[cnt++]=x%10;
        x/=10;
    }
    for(int i=0;i<=(cnt-1)/2;++i) {
        if(temp[cnt-1-i]!=temp[i]) return false;
    }
    return true;
}

int main() {
    int ans=0;
    for(int a=100;a<1000;++a) {
        for(int b=100;b<1000;++b) {
            if(judge(a*b)) {
                ans=max(ans,a*b);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}