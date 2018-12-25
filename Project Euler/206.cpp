#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool dfs(int depth,ll res) {
    if(depth==9) {
        res=res*1000+900;
        // printf("%lld\n",res);
        ll p=sqrt(res);
        if(p*p==res) {
            printf("%lld %lld\n",p,res);
            return true;
        }
        return false;
    }
    res=res*10+depth;
    for(int i=9;i>=0;--i) {
        if(dfs(depth+1,res*10+i)) return true;
    }
    return false;
}

int main() {
    dfs(1,0);
    return 0;
}