#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;
bool vis[maxn];

int main() {
    int cnt=0;
    for(int i=2;i<maxn;++i) {
        if(!vis[i]) {
            cnt++;
            if(cnt==10001) {
                printf("%d\n",i);
                break;
            }
            for(int j=2*i;j<maxn;j+=i) vis[j]=1;
        }
    }
    return 0;
}