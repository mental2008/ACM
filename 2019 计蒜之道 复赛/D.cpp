#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define MP make_pair
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=5e6+5;
char s[maxn];
int n,k;
char ans[maxn];
queue<int> q[26];

int main() {
    scanf("%s",s+1);
    scanf("%d",&k);
    n=strlen(s+1);
    rep(i,1,n-k+1) {
        q[s[i]-'a'].push(i);
    }
    int res=0;
    rep(i,1,k) {
        rep(j,0,25) {
            while(!q[j].empty()) {
                if(q[j].front()>res) break;
                q[j].pop();
            }
            if(!q[j].empty()) {
                res=q[j].front();
                break;
            }
        }
        ans[i]=s[res];
        if(i!=k) {
            q[s[n-k+1+i]-'a'].push(n-k+1+i);
        }
    }
    rep(i,1,k) printf("%c",ans[i]);
    puts("");
    return 0;
}