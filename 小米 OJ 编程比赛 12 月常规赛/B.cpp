#include<bits/stdc++.h>

using namespace std;

const int maxn=1e4+5;
vector<int> vec;
int SG[maxn];
bool vis[505];

int main() {
    int f1=1,f2=2;
    vec.push_back(1);
    vec.push_back(2);
    while(1) {
        int temp=f2;
        f2=f1+f2;
        f1=temp;
        if(f2>=maxn) break;
        vec.push_back(f2);
    }
    for(int i=1;i<maxn;++i) {
        int len=(int)vec.size();
        memset(vis,0,sizeof(vis));
        for(int j=0;j<len;++j) {
            if(vec[j]>i) break;
            vis[SG[i-vec[j]]]=1;
        }
        for(int j=0;;++j) {
            if(!vis[j]) {
                SG[i]=j;
                break;
            }
        }
    }
    int a,b;
    while(~scanf("%d%d",&a,&b)) {
        if((SG[a]^SG[b])==0) puts("Xiaobing Win");
        else puts("Xiaoai Win");
    }
    return 0;
}