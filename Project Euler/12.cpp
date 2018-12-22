#include<bits/stdc++.h>

using namespace std;

int main() {
    int p=0;
    for(int i=1;;++i) {
        p+=i;
        int cnt=0;
        for(int j=1;j*j<=p;++j) {
            if(j*j==p) cnt++;
            else if(p%j==0) cnt+=2;
        }
        if(cnt>500) {
            printf("%d\n",p);
            break;
        }
    }
    return 0;
}