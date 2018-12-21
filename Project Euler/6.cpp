#include<bits/stdc++.h>

using namespace std;

int main() {
    int n=100;
    int ans=n*(n+1)*(2*n+1)/6-n*n*(n+1)*(n+1)/4;
    printf("%d\n",-ans);
    return 0;
}