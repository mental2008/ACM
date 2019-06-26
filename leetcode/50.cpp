#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n) {
    if(n==0) return 1.0;
    if(n==-1) return 1.0/x;
    if(n==1) return x;
    double res=myPow(x,n/2);
    res=res*res;
    res=res*myPow(x,n-n/2*2);
    return res;
}

int main() {
    cout<<myPow(2.000,10)<<"\n";
    return 0;
}