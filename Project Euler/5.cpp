#include<bits/stdc++.h>

using namespace std;

int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y) {
    return x/gcd(x,y)*y;
}

int main() {
    int ans=1;
    for(int i=1;i<=20;++i) {
        ans=lcm(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}