#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    scanf("%lld",&n);
    if(n%4==0) puts("0");
    else if(n%4==3) puts("0");
    else puts("1");
    return 0;
}