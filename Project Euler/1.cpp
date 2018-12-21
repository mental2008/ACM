#include<bits/stdc++.h>

using namespace std;

const int maxn=999;

int main() {
    int ans=0;
    int n=maxn/3;
    ans+=3*(n+1)*n/2;
    n=maxn/5;
    ans+=5*(n+1)*n/2;
    n=maxn/15;
    ans-=15*(n+1)*n/2;
    printf("%d\n",ans);
    return 0;
}