#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
const int maxn=505;
struct Node {
    int id;
    int deg;
    bool operator<(const Node& e) const {
        return deg<e.deg;
    }
} node[maxn];
int n;
int cnt[maxn];
vector<int> e[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d",&node[i].deg);
        node[i].id=i;
    }
    sort(node+1,node+1+n);
    int one=0;
    rep(i,1,n) {
        if(node[i].deg==1) one++;
    }
    if(one<=1) {
        printf("YES %d\n",n-1);
        printf("%d\n",n-1);
        rep(i,1,n-1) {
            printf("%d %d\n",node[i].id,node[i+1].id);
        }
    }
    else if(one==2) {
        printf("YES %d\n",n-1);
        printf("%d\n",n-1);
        printf("%d %d\n",node[1].id,node[3].id);
        printf("%d %d\n",node[2].id,node[n].id);
        rep(i,3,n-1) {
            printf("%d %d\n",node[i].id,node[i+1].id);
        }
    }
    else {
        if(one==n) puts("NO");
        else {
            rep(i,1,n) cnt[node[i].id]=node[i].deg;
            if(one==n-1) {
                e[node[1].id].pb(node[n].id);
                e[node[2].id].pb(node[n].id);
                cnt[node[n].id]-=2;
                rep(i,3,one) {
                    if(cnt[node[n].id]==0) {
                        return 0*puts("NO");
                    }
                    cnt[node[n].id]--;
                    e[node[i].id].pb(node[n].id);
                }
                printf("YES 2\n");
                printf("%d\n",n-1);
                rep(i,1,n) {
                    int len=e[i].size();
                    rep(j,0,len-1) {
                        printf("%d %d\n",i,e[i][j]);
                    }
                }
            }
            else {
                e[node[1].id].pb(node[n-1].id);
                e[node[2].id].pb(node[n].id);
                cnt[node[n-1].id]--;
                cnt[node[n].id]--;
                if(one==n-2) {
                    e[node[n-1].id].pb(node[n].id);
                    cnt[node[n-1].id]--;
                    cnt[node[n].id]--;
                }
                else {
                    rep(i,one+1,n-3) {
                        e[node[i].id].pb(node[i+1].id);
                        cnt[node[i].id]--;
                        cnt[node[i+1].id]--;
                    }
                    if(cnt[node[one+1].id]==0||cnt[node[n-1].id]==0) {
                        return 0*puts("NO");
                    }
                    e[node[one+1].id].pb(node[n-1].id);
                    cnt[node[one+1].id]--;
                    cnt[node[n-1].id]--;
                    if(cnt[node[n-2].id]==0||cnt[node[n].id]==0) {
                        return 0*puts("NO");
                    }
                    e[node[n-2].id].pb(node[n].id);
                    cnt[node[n-2].id]--;
                    cnt[node[n].id]--;
                }
                rep(i,3,one) {
                    bool ok=false;
                    rep(j,one+1,n) {
                        if(cnt[node[j].id]) {
                            ok=true;
                            e[node[i].id].pb(node[j].id);
                            cnt[node[j].id]--;
                            break;
                        }
                    }
                    if(!ok) return 0*puts("NO");
                }
                printf("YES %d\n",n-one+1);
                printf("%d\n",n-1);
                rep(i,1,n) {
                    int len=e[i].size();
                    rep(j,0,len-1) {
                        printf("%d %d\n",i,e[i][j]);
                    }
                }
            }
        }
    }
    return 0;
}