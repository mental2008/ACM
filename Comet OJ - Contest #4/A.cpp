#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        int cnt[6];
        mem(cnt,0);
        rep(i,1,5) {
            int val;
            scanf("%d",&val);
            cnt[val]++;
        }
        int Max=0;
        rep(i,1,5) Max=max(Max,cnt[i]);
        rep(i,1,5) {
            if(cnt[i]==Max) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}