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

const int maxn=1005;
int n,m,k;
char s[maxn][maxn];
int num[maxn][maxn];
vector<int> row;
vector<int> col;
vector<int> ans;
vector<int> temp;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d%d%d",&n,&m,&k);
        rep(i,1,n) scanf("%s",s[i]+1);
        rep(i,1,n) {
            rep(j,1,m) {
                num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+(s[i][j]=='0');
            }
        }
        int sum=num[n][m];
        if(sum==0) {
            rep(i,1,k) printf("%d%c",i,i==k?'\n':' ');
            continue;
        }
        ans.clear();
        rep(a,1,min(k,n-1)) {
            int b=k-a;
            if(b<0||b>=m) continue;
            if(sum%((a+1)*(b+1))) continue;
            row.clear();
            int lst=0;
            rep(j,1,n-1) {
                if(num[j][m]-lst==sum/(a+1)) {
                    lst=num[j][m];
                    row.pb(j);
                }
            }
            if(num[n][m]-lst!=sum/(a+1)) continue;
            if(a!=(int)row.size()) continue;
            row.pb(n);
            col.clear();
            lst=0;
            rep(j,1,m-1) {
                if(num[n][j]-lst==sum/(b+1)) {
                    lst=num[n][j];
                    col.pb(j);
                }
            }
            if(num[n][m]-lst!=sum/(b+1)) continue;
            if(b!=(int)col.size()) continue;
            col.pb(m);
            bool ok=true;
            for(int i=1;i<row.size()&&ok;++i) {
                for(int j=1;j<col.size()&&ok;++j) {
                    if(num[row[i]][col[j]]-num[row[i]][col[j]-1]-num[row[i]-1][col[j]]+num[row[i]-1][col[j]-1]) ok=false;
                }
            }
            if(ok) {
                temp.clear();
                int len=(int)row.size();
                rep(j,0,len-2) temp.pb(row[j]);
                len=(int)col.size();
                rep(j,0,len-2) temp.pb(col[j]+n-1);
                // rep(j,0,k-1) printf("%d%c",ans[j],j==k-1?'\n':' ');
                if(ans.empty()||ans>temp) ans=temp;
            }
        }
        if(ans.empty()) puts("Impossible");
        else rep(j,0,k-1) printf("%d%c",ans[j],j==k-1?'\n':' ');
    }
    return 0;
}