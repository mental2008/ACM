#include<bits/stdc++.h>

using namespace std;
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+5;
int n;
vector<int> vec;
vector<int> fuckzero;
struct Node {
    ll val;
    int id;
    bool operator<(const Node& e) const {
        return val<e.val;
    }
} node[maxn];
bool vis[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%lld",&node[i].val);
        node[i].id=i;
    }
    sort(node+1,node+1+n);
    int neg=0;
    ll x=-INF,index=0;
    int zero=0;
    fuckzero.clear();
    rep(i,1,n) {
        if(node[i].val<0) {
            neg++;
            if(node[i].val>x) {
                x=node[i].val;
                index=node[i].id;
            }
        }
        else if(node[i].val==0) {
            zero++;
            fuckzero.push_back(node[i].id);
        }
    }
    mem(vis,0);
    if(neg%2==1) {
        if(zero>=1) {
            int len=(int)fuckzero.size();
            per(i,len-1,1) {
                vis[fuckzero[i]]=1;
                printf("1 %d %d\n",fuckzero[i],fuckzero[i-1]);
            }
            vis[fuckzero[0]]=1;
            vis[index]=1;
            cout<<"1 "<<index<<" "<<fuckzero[0]<<"\n";
            if(len+1<n) printf("2 %d\n",fuckzero[0]);
        }
        else {
            vis[index]=1;
            printf("2 %d\n",index);
        }
    }
    else {
        if(zero>=1) {
            int len=(int)fuckzero.size();
            per(i,len-1,1) {
                vis[fuckzero[i]]=1;
                printf("1 %d %d\n",fuckzero[i],fuckzero[i-1]);
            }
            vis[fuckzero[0]]=1;
            if(len<n) printf("2 %d\n",fuckzero[0]);
        }
    }
    vec.clear();
    rep(i,1,n) {
        if(!vis[i]) vec.push_back(i);
    }
    int len=(int)vec.size();
    rep(i,0,len-2) {
        printf("1 %d %d\n",vec[i],vec[i+1]);
    }
    return 0;
}
