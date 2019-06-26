#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=4100;
int dp[maxn];
ll l[15];
int vec[15];
int pre[maxn];
int sum[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    rep(T,1,caseCnt) {
        mem(dp,0);
        rep(i,0,11) scanf("%lld",&l[i]);
        rep(i,0,11) {
            rep(j,i+1,11) {
                rep(k,j+1,11) {
                    int pos=(1<<i)+(1<<j)+(1<<k);
                    if(l[i]+l[j]>l[k]&&l[i]+l[k]>l[j]&&l[j]+l[k]>l[i]) {
                        dp[pos]=1;
                        // printf("%lld %lld %lld\n",l[i],l[j],l[k]);
                    }
                }
            }
        }
        // printf("%d\n",dp[7]);
        rep(i,0,(1<<12)-1) {
            int cnt=0;
            rep(j,0,11) {
                if((i>>j)&1) {
                    cnt++;
                    vec[cnt]=j;
                }
            }
            sum[i]=cnt;
            pre[i]=-1;
            if(cnt%3) continue;
            if(cnt<=3) continue;
            rep(j,1,cnt) {
                rep(k,j+1,cnt) {
                    rep(p,k+1,cnt) {
                        int pos=(1<<vec[j])+(1<<vec[k])+(1<<vec[p]);
                        if(dp[i]<dp[i^pos]+dp[pos]) {
                            dp[i]=dp[i^pos]+dp[pos];
                            pre[i]=i^pos;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",T,dp[(1<<12)-1]);
        int res=(1<<12)-1;
        while(1) {
            if(sum[res]==3&&dp[res]==1) {
                int pos=res;
                int m=0;
                rep(i,0,11) {
                    if((pos>>i)&1) {
                        vec[++m]=i;
                    }
                }
                // printf("*%d %d %d\n",vec[1],vec[2],vec[3]);
                printf("%lld %lld %lld\n",l[vec[1]],l[vec[2]],l[vec[3]]);
                // res=pre[res];
                break;
            }
            if(pre[res]==-1) break;
            if(sum[res]<=2) break;
            if(sum[res]%3==0) {
                int pos=res^pre[res];
                int m=0;
                rep(i,0,11) {
                    if((pos>>i)&1) {
                        vec[++m]=i;
                    }
                }
                // printf("*%d %d %d\n",vec[1],vec[2],vec[3]);
                if(dp[pos]==1)
                    printf("%lld %lld %lld\n",l[vec[1]],l[vec[2]],l[vec[3]]);
            }
            res=pre[res];
        }
    }
    return 0;
}