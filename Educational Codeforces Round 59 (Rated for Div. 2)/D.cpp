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
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=5205;

char s[maxn][maxn];
char ch[maxn];
int n;
vector<int> vec;
int pre[maxn][maxn];

void work(int p,int l,int r,int num) {
    int temp[4];
    mem(temp,0);
    int index=0;
    // printf("%d\n",num);
    while(num) {
        temp[index++]=num%2;
        num/=2;
    }
    rep(i,0,3) {
        s[p][l+i]=temp[3-i]+'0';
        // putchar(s[i][l+i]);
    }
    // putchar('\n');
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%s",ch+1);
        rep(j,1,n/4) {
            char p=ch[j];
            int num;
            if(p>='0'&&p<='9') num=p-'0';
            else num=p-'A'+10;
            work(i,j*4-3,j*4,num);
        }
    }
    // rep(i,1,n) {
    //     rep(j,1,n) {
    //         printf("%c",s[i][j]);
    //     }
    //     puts("");
    // }
    rep(i,1,n) {
        rep(j,1,n) {
            pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+(s[i][j]-'0');
        }
    }
    for(int i=1;i*i<=n;++i) {
        if(n%i==0) {
            vec.pb(i);
            vec.pb(n/i);
        }
    }
    sort(vec.begin(),vec.end());
    int len=(int)vec.size();
    per(p,len-1,0) {
        int x=vec[p];
        // printf("%d\n",x);
        bool ok=true;
        rep(i,1,n/x) {
            rep(j,1,n/x) {
                int res=pre[x*i][x*j]-pre[x*(i-1)][x*j]-pre[x*i][x*(j-1)]+pre[x*(i-1)][x*(j-1)];
                // printf("%d %d %d %d\n",x,(n/x)*i,(n/x)*j,res);
                if(res==x*x||res==0) continue;
                ok=false;
                break;
            }
            if(!ok) break;
        }
        if(ok) return 0*printf("%d\n",x);
    }
    return 0;
}