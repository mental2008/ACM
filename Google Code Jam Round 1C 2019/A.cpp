#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>

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

const int maxn=305;
int n;
char s[maxn*2];
int root;
int ch[500005][3];
char ans[maxn*2];
int cnt;
bool chk;

void insert(int len) {
    int rt=root;
    rep(i,0,len-1) {
        if(ch[rt][s[i]-'A']==0) {
            ch[rt][s[i]-'A']=++cnt;
            mem(ch[cnt],0);
        }
        rt=ch[rt][s[i]-'A'];
    }
}
int f;
void dfs(int rt,int depth) {
    vector<int> v;
    rep(i,0,2) {
        if(ch[rt][i]) v.pb(i);
    }
    int res=(int)v.size();
    if(res==3) { chk=false; return; }
    if(res==0) {
        if(f==0) ans[depth]=1;
        if(f==1) ans[depth]=2;
        if(f==2) ans[depth]=0;
        rep(i,0,depth) {
            if(ans[i]==0) printf("S");
            if(ans[i]==1) printf("R");
            if(ans[i]==2) printf("P");
        }
        return;
    }
    if(res==1) {
        ans[depth]=v[0];
        if(depth==0) f=v[0];
        dfs(ch[rt][v[0]],depth+1);
    }
    else {
        if(v[0]==0&&v[1]==1) {
            ans[depth]=1;
            if(depth==0) f=1;
            dfs(ch[rt][1],depth+1);
        }
        if(v[0]==0&&v[1]==2) {
            ans[depth]=0;
            if(depth==0) f=0;
            dfs(ch[rt][0],depth+1);
        }
        if(v[0]==1&&v[1]==2) {
            ans[depth]=2;
            if(depth==0) f=2;
            dfs(ch[rt][2],depth+1);
        }
    }
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    rep(T,1,caseCnt) {
        int n;
        scanf("%d",&n);
        root=cnt=1;
        mem(ch[1],0);
        rep(i,1,n) {
            scanf("%s",s);
            int len=strlen(s);
            rep(j,0,len-1) {
                if(s[j]=='S') s[j]='A';
                if(s[j]=='R') s[j]='B';
                if(s[j]=='P') s[j]='C';
            }
            rep(j,len,499) s[j]=s[j%len];
            insert(500);
        }
        chk=true;
        printf("Case #%d: ",T);
        dfs(1,0);
        if(!chk) printf("IMPOSSIBLE");
        puts("");
    }
    return 0;
}